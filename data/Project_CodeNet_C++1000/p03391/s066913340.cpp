#include <bits/stdc++.h>
#define oo 200005
using namespace std;
int n, a[oo], b[oo];
long long ans, tmp = 1e18;
int main ()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i)
    scanf("%d%d", &a[i], &b[i]);
    for(int i = 1; i <= n; ++ i)
    {
        ans += a[i];
        if(a[i] > b[i]) tmp = min(tmp, 1ll * b[i]);
    }
    if(tmp == 1e18) puts("0");
    else printf("%lld", ans - tmp);
    return 0;
}