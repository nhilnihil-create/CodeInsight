#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll n, mx = -1, mi;
vector<ll> ve[200005];

void dfs(ll p, ll q, ll r)
{
    if(r > mx) mx = r, mi = p;
    for(ll i = 0; i < ve[p].size(); i++)
    {
        if(ve[p][i] == q) continue;
        dfs(ve[p][i], p, r + 1);
    }
}

int main()
{
    scanf("%lld", &n);
    for(ll i = 1; i < n; i++)
    {
        ll t1, t2;
        scanf("%lld%lld", &t1, &t2);
        ve[t1].push_back(t2);
        ve[t2].push_back(t1);
    }
    dfs(1, 0, 0);
    dfs(mi, 0, 0);
    if(mx % 3 == 1) printf("Second\n");
    else printf("First\n");
    return 0;
}
