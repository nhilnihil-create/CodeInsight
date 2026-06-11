#include<stdio.h>
int main()
{
    int n,m,x,a[100000];
    scanf("%d %d %d",&n,&m,&x);
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    int cost;
    int mid = (n/2)+1;
    if(x == 0)
        printf("0");
    else if(x == n)
        printf("0");
    else
 {
         int cost = 0;
        for(int i = x;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            if(a[j]>0 &&a[j]<n && a[j] == i)
              {
                  cost++;
              }
        }
        int save1 = cost;
        cost = 0;
        for(int i = x;i>=0;i--)
        {
            for(int j = 1;j<=m;j++)
            if(a[j]>0 &&a[j]<n && a[j] == i)
              {
                  cost++;
              }
        }
        int save2 = cost;
        if(save1 > save2)
            printf("%d\n",save2);
        else
            printf("%d\n",save1);
  }
}

