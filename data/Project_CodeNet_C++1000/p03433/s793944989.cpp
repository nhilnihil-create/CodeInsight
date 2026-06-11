#include<stdio.h>
int main()
{
   int n,a;scanf("%d%d",&n,&a);
   if(n>=500)
   {
       int d=n%500;
       if(d==0||d<=a)printf("Yes");
       else printf("No");
   }
   else if(n<500)
   {
       if(n<=a)printf("Yes");
       else printf("No");
   }
}
