#include<stdio.h>
#include<math.h>


int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);

    int p;
   if(a>b)
    p=a-b-1;
   else
    p=b-a-1;

    if(p%2==1)
        printf("Alice");
    else
        printf("Borys");

}




