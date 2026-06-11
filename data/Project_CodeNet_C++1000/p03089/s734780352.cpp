#include <bits/stdc++.h>
using namespace std;
#define Maxn 107
int n,a[Maxn];
int m=0,ans[Maxn];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        if (a[i]-i>0)
        {
            printf("%d\n",-1);
            return 0;
        }
    while (n>0)
    {
        int pos=-1;
        for (int i=n;i;i--)
            if (a[i]==i)
            {
                pos=i;
                break;
            }
        if (pos==-1)
        {
            printf("%d\n",-1);
            return 0;
        }
        ans[++m]=pos;
        for (int i=pos+1;i<=n;i++)
            a[i-1]=a[i];
        --n;
    }
    for (int i=1;i<m+1-i;i++)
        swap(ans[i],ans[m+1-i]);
    for (int i=1;i<=m;i++)
        if (ans[i]>i)
        {
            printf("%d\n",-1);
            return 0;
        }
    for (int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}