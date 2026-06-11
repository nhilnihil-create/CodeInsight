#include <bits/stdc++.h>
using namespace std;
#define modp 1000000007
#define Maxn 200007
int n,a[Maxn],f[Maxn],s[Maxn];
int main()
{
    scanf("%d",&n);
    int m=1;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=2;i<=n;i++)
        if (a[i]!=a[m]) a[++m]=a[i];
    n=m;
    f[0]=1;
    for (int i=1;i<=n;i++)
    {
        f[i]=(f[i-1]+s[a[i]])%modp;
        s[a[i]]=f[i];
    }
    printf("%d\n",f[n]);
    return 0;
}