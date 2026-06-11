#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define all(v) v.begin(),v.end() 
#define rev(v) v.rbegin(),v.rend()
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define inp 200005
#define en "\n"
using namespace std;
using namespace __gnu_pbds;

vector<int> adj[inp], par[inp], topo;
bool vis[inp];

void dfs(int s)
{
    vis[s] = 1;
    for(int i:adj[s])
    {
        if(!vis[i]) dfs(i);
    }
    topo.push_back(s);
}
signed main() 
{
    ssd
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>j>>k;
        adj[j].push_back(k);
        par[k].push_back(j);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i]) dfs(i);
    }
    reverse(all(topo));
    ll dp[n+5] = {};
    ll ans=0;
    for(i=0;i<n;i++)
    {
        for(int j: par[topo[i]])
        {
            dp[topo[i]] = max(dp[topo[i]], 1+dp[j]);
            ans = max(ans,dp[topo[i]]);
        }
    }
    cout<<ans;
    return 0;             
}