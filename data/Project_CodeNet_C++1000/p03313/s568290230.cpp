#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll a[300005];
ll d[300005];

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < (1 << n); i++)
    {
        scanf("%lld", &a[i]);
    }
    for(ll i = 1; i < (1 << n); i++)
    {
        ll t = i;
        d[i] = d[i - 1];
        ll mx1 = a[0], mx2 = 0;
        for(ll j = t; j > 0; j = ((j - 1) & i))
        {
            if(mx1 < a[j]) mx2 = mx1, mx1 = a[j];
            else if(mx2 < a[j]) mx2 = a[j];
        }
        d[i] = max(d[i - 1], mx1 + mx2);
        printf("%lld\n", d[i]);
    }
    return 0;
}
