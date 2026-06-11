#include<stdio.h>
int main()
{
    int N;scanf("%d",&N);
    int a[10000],i,j,sum=0,max,t;
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    max=a[0];
    for(j=1;j<N;j++)
    {
      if(max<a[j])
      {
          max=a[j];
      }
    }
    for(i=0;i<N;i++)
    {
      sum+=a[i];
    }
    sum+=(max/2)-max;
    printf("%d",sum);
    return 0;
}
