#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FAST()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define fill(a, i) memset(a, i, sizeof(a))
#define all(vec) vec.begin(),vec.end()
#define revall(vec) vec.rbegin(),vec.rend()
#define vl vector<ll>
#define tlll tuple<ll, ll, ll>
#define pb push_back
#define fr(i, a, b) for (int i = a; i < b; ++i)  
ll mod=1e9+7;
const ll maxn=1e5+5;
vl adj[maxn]; 
ll dp[maxn][2];
ll n;
bool visited[maxn];
ll dfs(ll u,ll p,ll idx)
{ 
    if(visited[u])
    { 
        ll ans = idx==1?dp[u][0]:dp[u][1]+dp[u][0]; 
        return ans%mod;
    }
    visited[u]=1;
    fr(k,0,2)
    {
        ll temp=1;
        fr(i,0,adj[u].size())
        {
            if(adj[u][i]!=p) 
            temp=(temp*dfs(adj[u][i],u,k))%mod;
            
        } 
        dp[u][k]=temp;
    }
    ll ans = idx==1?dp[u][0]:dp[u][1]+dp[u][0] ; 
    return ans%mod;
}
void solve()
{
    cin>>n;
    fr(i,0,n-1)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans=0;
    fr(k,0,2)
    {
        ll temp=1;
        temp=dfs(1,0,k); 
    } 
    cout<<(dp[1][0]+dp[1][1])%mod;
}
int main()
{
FAST();
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
}