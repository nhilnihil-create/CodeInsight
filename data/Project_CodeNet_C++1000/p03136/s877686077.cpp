#include<stdio.h>
int main()
{
    int i,j,s=0,m=0,n,x,y;
    scanf("%d", &n);
    int a[n+5];
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
        if(a[i]>m)
            m=a[i];
        s=s+a[i];
    }
    s=s-m;
    if(s>m)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
