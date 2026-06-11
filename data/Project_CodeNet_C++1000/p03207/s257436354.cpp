#include<stdio.h>

int main()
{
    int n,a[20],max=-1,i,sum=0,div,p;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        if(a[i]>max)
        {
            max = a[i];
            p = i;
        }

    }

    div = max/2;

    for(i=1;i<=n;i++)
    {
        if(i!=p)
            sum = sum + a[i];
    }

    sum = sum + div;

    printf("%d\n",sum);

    return 0;
}
