#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db long double
#define pow pw
const db pi = 3.14159265358979323846;
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
const int mxn=1e5+7;
int n,m;
vector<int> g[mxn];
int dp[mxn],vis[mxn],in_degree[mxn];
void dfs(int u)
{
    vis[u]=1;
    for(int v : g[u]) 
    {
        dp[v]=max(dp[v],dp[u]+1);
        in_degree[v]--;
        if (in_degree[v]==0) dfs(v);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        in_degree[v]++;
    }
    for (int i=1;i<=n;i++)
    if (!vis[i]&&in_degree[i]==0) dfs(i);
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,dp[i]);
    cout<<ans;
    return 0;
}