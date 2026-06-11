#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define F first
#define S second

using namespace std;

typedef long long ll;

ll n;
pair<ll, ll> a[100005], b[100005];
ll c[100005], d[100005];
bool v[100005];
ll ans1, ans2, now;

ll f(ll p)
{
    ll t = 0;
    if(c[p] <= now && now <= d[p]) return 0;
    if(c[p] > now)
    {
        t = now;
        now = c[p];
        return c[p] - t;
    }
    if(d[p] < now)
    {
        t = now;
        now = d[p];
        return t - d[p];
    }
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld", &a[i].F, &b[i].F);
        a[i].S = i, b[i].S = i;
        c[i] = a[i].F;
        d[i] = b[i].F;
    }
    sort(a, a + n, greater<pair<ll, ll> >());
    sort(b, b + n);
    now = 0;
    for(ll i = 0; i < n; i++) v[i] = false;
    for(ll i = 0, j = 0; i < n && j < n; )
    {
        while(v[a[i].S] && i < n) i++;
        if(i >= n) break;
        ans1 += f(a[i].S);
        v[a[i].S] = true;
        while(v[b[j].S] && j < n) j++;
        if(j >= n) break;
        ans1 += f(b[j].S);
        v[b[j].S] = true;
    }
    ans1 += abs(now);
    now = 0;
    for(ll i = 0; i < n; i++) v[i] = false;
    for(ll i = 0, j = 0; i < n && j < n; )
    {
        while(v[b[j].S] && j < n) j++;
        if(j >= n) break;
        ans2 += f(b[j].S);
        v[b[j].S] = true;
        while(v[a[i].S] && i < n) i++;
        if(i >= n) break;
        ans2 += f(a[i].S);
        v[a[i].S] = true;
    }
    ans2 += abs(now);
    printf("%lld\n", max(ans1, ans2));
    return 0;
}
