#include<stdio.h>
#include <stdlib.h>
#define size 12
int comp(int *c,int *d)
{
    return (*d-*c);
}
int main()
{
    int a[size],n,i,j,sum=0,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //qsort(a,n,sizeof(int),comp);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                t=a[i];a[i]=a[j];a[j]=t;
            }
        }
    }
    for(i=1;i<n;i++)
    {
        sum+=a[i];
    }
    if(sum>a[0])printf("Yes");
    else printf("No");
}
