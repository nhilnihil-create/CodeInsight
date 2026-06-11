#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll h, w, n;
ll a[200005];

int main()
{
    scanf("%lld%lld%lld", &h, &w, &n);
    for(ll i = 1; i <= h; i++)
    {
        a[i] = w + 1;
    }
    for(ll i = 0; i < n; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        a[t1] = min(a[t1], t2);
    }
    ll now = 1;
    for(ll i = 2; i <= h; i++)
    {
        if(a[i] <= now)
        {
            printf("%lld\n", i - 1);
            return 0;
        }
        else
        {
            if(a[i] != now + 1) now++;
        }
    }
    printf("%lld\n", h);
    return 0;
}
