#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll n, m;
vector<ll> ve[100005];
ll a[100005];

bool f(ll p, ll q)
{
    if(a[p] == 3 - q)
    {
        return false;
    }
    if(a[p] == q) return true;
    a[p] = q;
    for(ll i = 0; i < ve[p].size(); i++)
    {
        if(!f(ve[p][i], 3 - q)) return false;
    }
    return true;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    for(ll i = 0; i < m; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    if(f(1, 1))
    {
        ll cnt = 0;
        for(ll i = 1; i <= n; i++) if(a[i] == 1) cnt++;
        printf("%lld\n", cnt * (n - cnt) - m);
    }
    else printf("%lld\n", n * (n - 1) / 2 - m);
    return 0;
}
