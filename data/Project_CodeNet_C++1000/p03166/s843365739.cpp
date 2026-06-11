#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int lli;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<pll> vop;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define REP(i,a,b) for( long long i=a;i<b;i++)
#define PB push_back
#define N 200007

vl g[N];
bool vis[N];
ll dis[N];
ll ans = 0;

void dfs(ll v)
{
    vis[v] = true;
    for (auto u : g[v])
    {
        if (!vis[u])
            dfs(u);
        dis[v] = max(dis[v], 1 + dis[u]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fastIO;
    int test = 1, num = 1;
    //cin >> test;
    while (test--)
    {
        ll n, m;
        cin >> n >> m;
        REP(i, 0, m)
        {
            ll u, v;
            cin >> u >> v;
            g[u].PB(v);
        }
        REP(i, 1, n + 1)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
        REP(i, 1, n + 1) ans = max(ans, dis[i]);
        cout << ans << endl;
    }
    return 0;
}