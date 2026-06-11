#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll a[100005];
ll ans;
ll mx, mn;

ll f(ll p)
{
    for(ll i = 1; i <= n; i++)
    {
        p = p / a[i] * a[i];
    }
    return p;
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    ll lt, rt, mid, ans;
    lt = 2;
    rt = 4e18;
    while(lt <= rt)
    {
        mid = (lt + rt) / 2;
        if(f(mid) > 2) rt = mid - 1;
        else ans = mid, lt = mid + 1;
    }
    mx = ans;
    lt = 2;
    rt = 4e18;
    while(lt <= rt)
    {
        mid = (lt + rt) / 2;
        if(f(mid) < 2) lt = mid + 1;
        else ans = mid, rt = mid - 1;
    }
    mn = ans;
    if(mn > mx) printf("-1\n");
    else printf("%lld %lld\n", mn, mx);
    return 0;
}
