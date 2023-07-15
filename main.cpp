#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char date[100];
char student_name[100];
char breakfast_item[100];
int breakfast_cost;
char lunch_item[100];
int lunch_cost;
char dinner_item[100];
int dinner_cost;
int total_cost;
int payment;
int unpaid;
int n,i;

//function for data entry information:
void write(){
FILE*fp;
char dat[100];
char student_nam[100];
char breakfast_itm[100];
int breakfast_cst;
char lunch_itm[100];
int lunch_cst;
char dinner_itm[100];
int dinner_cst;
int total_cst;
int paymnt;
int unpad;

printf("\nEnter the Date: ");
scanf("%s",&dat);
printf("\nEnter the student_name: ");
scanf("%s",&student_nam);
printf("\nEnter the breakfast_item: ");
scanf("%s",&breakfast_itm);
printf("\nEnter the breakfast_cost: ");
scanf("%d",&breakfast_cst);
printf("\nEnter the lunch_item: ");
scanf("%s",&lunch_itm);
printf("\nEnter the lunch_cost: ");
scanf("%d",&lunch_cst);
printf("\nEnter the dinner_item: ");
scanf("%s",&dinner_itm);
printf("\nEnter the dinner_cost: ");
scanf("%d",&dinner_cst);
printf("\nEnter the total_cost: ");
total_cst=(breakfast_cst+lunch_cst+dinner_cst);
printf("%d\n",total_cst);
printf("\nPayment amount: ");
scanf("%d",&paymnt);
printf("\nUnpaid amount: ");
unpad = ((breakfast_cst+lunch_cst+dinner_cst)-paymnt);
printf("%d\n",unpad);

fp=fopen("Record.txt","a");
fprintf(fp,"\n%s %s %s %d %s %d %s %d %d %d %d\n",dat,student_nam,breakfast_itm,breakfast_cst,lunch_itm,lunch_cst,dinner_itm,dinner_cst,total_cst,paymnt,unpad);
printf("\n Record written successfully!!!");
fclose(fp);
}
//function to search record by date
void display(char da[]){
    FILE*fp;
    int res;
    fp=fopen("record.txt","r");
    while(fscanf(fp,"\n%s%s%s%d%s%d%s%d%d%d%d\n",date,student_name,breakfast_item,&breakfast_cost,lunch_item,&lunch_cost,dinner_item,&dinner_cost,&total_cost,&payment,&unpaid)!=EOF){
        res = strcmp(date,da);
        if(res==0){
            printf("\n\n student_name= %s ",student_name);
            printf("\n breakfast_item= %s ",breakfast_item);
            printf("\n breakfast_cost= %d ",breakfast_cost);
            printf("\n lunch_item= %s ",lunch_item);
            printf("\n lunch_cost= %d ",lunch_cost);
            printf("\n dinner_item= %s ",dinner_item);
            printf("\n dinner_cost= %d ",dinner_cost);
            total_cost=(breakfast_cost+lunch_cost+dinner_cost);
            printf("\n total_cost= %d",total_cost);
            printf("\n payment= %d",payment);
            unpaid=((breakfast_cost+lunch_cost+dinner_cost)-payment);
            printf("\n unpaid= %d",unpaid);
        }
    }
    fclose(fp);
}

int main(){
        int ch;
        char lm[20];
        do{
            printf("\n\n***WELCOME TO SHEIKH REHANA HALL DINING***\n");
            printf("\n Press<1> to create entry.");
            printf("\n Press<2> to display specific date.");
            printf("\n Press<0> to exit.");

            printf("\n\nEnter choice::");
            scanf("%d",&ch);

            switch(ch){
                case 1:write();
                break;

                case 2:printf("\nEnter date::");
                scanf("%s",&lm);
                display(lm);
                break;

                case 0:exit(0);

                default:printf(" Invalid selection");
            }
        }
        while(ch!=0);
}
main.c
Displaying main.c.
