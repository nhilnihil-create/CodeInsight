#include <stdio.h>
#include <stdlib.h>
#define size 1000000

int main()
{
    int n,i,c = 0,a[size],b = 0;

    scanf("%d",&n);
    for(i=0;i<n;i++)

      scanf("%d",&a[i]);

      for(i=0;i<n;i++)
        {
        c += a[i];
        if(a[i]>b)
           b = a[i];
        }

      if((c-b)>b)printf("Yes\n");
      else printf("No\n");
    return 0;
}
