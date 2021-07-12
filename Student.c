#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
    char father[20];
};
int main(){
    char ch,pass[20];
    system("cls");
    gotoxy(10,2);
    printf("<--:Student Record Management System:-->");
    gotoxy(1,3);
    printf("----------------------------------------------------------------");
    gotoxy(1,7);
    printf("----------------------------------------------------------------");
    gotoxy(17,5);
    printf("Enter Password:");
    int i=0;
    while(1){
        ch=getch();
        if(ch==13){ //ASCII value of 'ENTER KEY'.
            pass[i]='\0';
            break;
        }
        pass[i]=ch;
        i++;
        printf("*");
    }
    if(strcmp(pass,"jains")==0){
        menu();
    }
    else{
        gotoxy(5,10);
        printf("Wrong Password .Press any key to continue.");
        getch();
    }
    return 0;
}
void menu(){
    char choice;
    system("cls");
    gotoxy(22,2);
    printf("*** Main Menu ***");
    gotoxy(0,3);
    printf("____________________________________________________________");
    gotoxy(10,5);
    printf("1 : Add Record.");
    gotoxy(10,6);
    printf("2 : View Record.");
    gotoxy(10,7);
    printf("3 : Search Record.");
    gotoxy(10,8);
    printf("4 : Modify Record.");
    gotoxy(10,9);
    printf("5 : Delete.");
    gotoxy(10,10);
    printf("6 : Exit.");
    gotoxy(0,11);
    printf("____________________________________________________________");
    gotoxy(10,13);
    printf("Enter your choice.");
    choice=getch();
    switch(choice)
    {
    case '1':
        add();
        break;

    case '2':
        view();
        break;

    case '3':
        search();
        break;

    case '4':
        modify();
        break;

    case '5':
        deleterec();
        break;

    case '6':
        exit(0);
        break;

    default:
    system("cls");
        gotoxy(10,2);
        printf("Invalid Choice.");
        exit(0);
    }
}
void add(){
    FILE *fp;
    struct student std;
    char ch ='y';
    system("cls");
    fp = fopen("record.txt","a+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(ch=='y'){
        gotoxy(10,2);
        printf("<--:ADD NEW STUDENT RECORD:-->");
        gotoxy(0,3);
        printf("____________________________________________________________");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name          : ");
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter Roll No       : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course        : ");
        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch        : ");
        gets(std.branch);
        gotoxy(10,12);
        printf("Enter Father's Name : ");
        gets(std.father);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(0,13);
        printf("____________________________________________________________");
        gotoxy(10,15);
        printf("Want to add of another record (Y/N):");
        fflush(stdin);
        ch=getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    fp = fopen("record.txt","r");
    if(fp == NULL){
        system("cls");
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    if (0 == size) {
        system("cls");
        printf("No Records Found...Press any key.");
        fclose(fp);
        getch();
        menu();
    }
    fclose(fp);
    fp = fopen("record.txt","r+");
    system("cls");
    gotoxy(22,2);
    printf("<--:VIEW STUDENTS RECORD:-->");
    gotoxy(0,3);
    printf("_________________________________________________________________________________");
    gotoxy(2,5);
    printf("S.No");
    gotoxy(8,5);
    printf("Name of Student");
    gotoxy(25,5);
    printf("Mobile No");
    gotoxy(38,5);
    printf("Roll No");
    gotoxy(48,5);
    printf("Course");
    gotoxy(57,5);
    printf("Branch");
    gotoxy(65,5);
    printf("Father's Name");
    gotoxy(0,6);
    printf("----------------------------------------------------------------------------------");
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(2,j);
        printf("%d",i);
        gotoxy(8,j);
        printf("%s",strupr(std.name));
        gotoxy(25,j);
        printf("%s",std.mobile);
        gotoxy(38,j);
        printf("%d",std.rollno);
        gotoxy(48,j);
        printf("%s",strupr(std.course));
        gotoxy(57,j);
        printf("%s",strupr(std.branch));
        gotoxy(65,j);
        printf("%s",strupr(std.father));
        i++;
        j++;
    }
    gotoxy(0,j+1);
    printf("----------------------------------------------------------------------------------");
    fclose(fp);
    gotoxy(2,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    int found=0;
    system("cls");
    gotoxy(15,2);
    printf("*** SEARCH RECORD ***");
    gotoxy(0,3);
    printf("_______________________________________________________________");
    gotoxy(0,6);
    printf("_______________________________________________________________");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","r");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmpi(stname,std.name) == 0){
            found=1;
            gotoxy(10,8);
            printf("Name          : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No       : %d",std.rollno);
            gotoxy(10,11);
            printf("Course        : %s",std.course);
            gotoxy(10,12);
            printf("Branch        : %s",std.branch);
            gotoxy(10,13);
            printf("Father's Name : %s",std.father);
            gotoxy(0,14);
            printf("_______________________________________________________________");
        }
    }
    if(found==0){
        gotoxy(10,15);
        printf("No Records Found.");
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    int found=0;
    struct student std;
    system("cls");
    gotoxy(18,0);
    printf("*** MODIFY RECORD ***");
    gotoxy(0,1);
    printf("_______________________________________________________________");
    gotoxy(6,3);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    gotoxy(0,4);
    printf("_______________________________________________________________");
    fp = fopen("record.txt","r+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmpi(stname,std.name) == 0){
            found=1;
            gotoxy(17,6);
            printf("!!! Enter New Details !!!");
            gotoxy(10,8);
            printf("Enter name          : ");
            gets(std.name);
            gotoxy(10,9);
            printf("Enter mobile number : ");
            gets(std.mobile);
            gotoxy(10,10);
            printf("Enter roll no       : ");
            scanf("%d",&std.rollno);
            gotoxy(10,11);
            printf("Enter Course        : ");
            fflush(stdin);
            gets(std.course);
            gotoxy(10,12);
            printf("Enter Branch        : ");
            fflush(stdin);
            gets(std.branch);
            gotoxy(10,13);
            printf("Enter Father's Name : ");
            fflush(stdin);
            gets(std.father);
            gotoxy(0,15);
            printf("_______________________________________________________________");
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    if(found==0){
        gotoxy(10,16);
        printf("No Records Found.");
    }
    fclose(fp);
    gotoxy(10,17);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    int found=0;
    struct student std;
    system("cls");
    gotoxy(18,1);
    printf("*** DELETE RECORD ***");
    gotoxy(0,2);
    printf("_______________________________________________________________");
    gotoxy(10,4);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","r");
    while(fread(&std,sizeof(std),1,fp)!=0){
        if(strcmpi(stname,std.name)==0)
            found=1;
    }
    if(found==0){
        fclose(fp);
        gotoxy(10,6);
        printf("Record Not Found.");        
        getch();
        menu();
    }
    fclose(fp);
    fp = fopen("record.txt","r");
    ft = fopen("temp.txt","a+");
    while(fread(&std,sizeof(std),1,fp)!=0){
        if(strcmpi(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,7);
    printf("Record Deleted Successfully.Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y){
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}