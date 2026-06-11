#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,c,d,m,n,x=0,y;

    scanf("%d%d%d%d",&a,&b,&c,&d);

    m=abs(a-b);

    n=abs(b-c);

    y=abs(a-c);

    if((m<=d && n<=d == 1)||y <= d)
    {
       printf("Yes\n");
    }

    else
    {
       printf("No\n");
    }

    return 0;
}
