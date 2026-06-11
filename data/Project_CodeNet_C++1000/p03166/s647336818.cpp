#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}
vector<ll> dp(100001, -1);
void dfs(ll s, vector< vector<ll> > &adj, vector<bool> &v)
{
    v[s] = true;
    ll child = 0;
    for(auto c: adj[s])
    {
        if(!v[c])
        {
            dfs(c, adj, v);
        }
        // if(dp[c] == -1)
        //     continue;
        dp[s] = max(dp[s], dp[c] + 1);
        child += 1;
    }
    if(!child)
    {
        dp[s] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n,m;
    cin>>n>>m;
    vector< vector<ll> > adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (ll i = 0; i < m; i++)
    {
        /* code */
        ll v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
    }
    ll ans = 0;
    for(ll i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i, adj, vis);
    }
    for(ll i=1; i<=n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout<<ans<<'\n';
}