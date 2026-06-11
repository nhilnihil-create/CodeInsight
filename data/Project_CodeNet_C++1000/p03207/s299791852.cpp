#include<stdio.h>
int main()
{
    int n,a[11],i,p,max=0,sum=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p);
        if(p>=max)
            max=p;
        sum=sum+p;
    }
    sum=sum-(max/2);
    printf("%d\n", sum);
    return 0;

}
