#include <bits/stdc++.h>
using namespace std;
#define Maxn 10007
int m,a[Maxn],b[Maxn],c[Maxn];
int n;
int main()
{
    scanf("%d",&n);
    if (n%2==0)
    {
        for (int i=1;i<=n/2;i++)
            c[i]=i,c[n+1-i]=i;
    } else
    {
        for (int i=1;i<=n/2;i++)
            c[i]=i,c[n-i]=i;
        c[n]=n;
    }
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (c[i]!=c[j])
            {
                ++m;
                a[m]=i;
                b[m]=j;
            }
    printf("%d\n",m);
    for (int i=1;i<=m;i++)
        printf("%d %d\n",a[i],b[i]);
    return 0;
}