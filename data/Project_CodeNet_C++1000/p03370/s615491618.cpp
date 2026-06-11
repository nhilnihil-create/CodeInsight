#include<stdio.h>
int main()
{
    int a[110],n,x,i,j,sum=0,min=1000000,ttl;
    scanf("%d%d\n",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<min)min=a[i];
    }
    for(i=0;i<n;i++)
    {
      sum+=a[i];
    }
    x-=sum;
    ttl=x/min;
    ttl+=n;
    printf("%d",ttl);
}
