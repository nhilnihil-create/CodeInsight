#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main ()
{
    int n;
    scanf("%d",&n);
    LL ans=0;
    bool same = true;
    int min_b = 1234567890;
    for (int i=1;n>=i;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        same &= (a==b);
        if (a<=b) ans += a;
        else min_b = min(b,min_b),ans+=a;
    }
    if (same) puts("0");
    else printf("%lld\n",ans-min_b);
}
