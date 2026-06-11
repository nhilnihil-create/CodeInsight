#include<iostream>
using namespace std;
int main()
{
    int n,n1,n2,n3;
    scanf("%d",&n);


    n1 = n % 100;
    n2 = n /100;
    n3 = n2 % 100;
    //printf("%d %d",n3,n1);
    if((n3==0 && n1 == 0) || (n3>12 && n1==0) || (n3==0 && n1>12) || (n3>12 && n1 > 12))
    {
        printf("NA");
    }
    else if(n3!=0 && n1!=0 )
    {
        if(n3<=12 && n1 <= 12)
            printf("AMBIGUOUS");
        else if(n3<=12 && n1>12)
        printf("MMYY");
        else if(n3>12 && n1<=12)
        printf("YYMM");
    }
    else if((n1==0 || n3==0))
    {
        if(n3==0)
            printf("YYMM");
        else if(n1==0)
            printf("MMYY");

    }


}