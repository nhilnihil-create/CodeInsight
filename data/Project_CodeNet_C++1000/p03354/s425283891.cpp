#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5,mod=1e9+7;
#define ll long long
int a[N],val[N],vis[N];
int visid=0;
vector<int> adj[N];
void dfs(int u)
{
    vis[u]=visid;
    val[a[u]]=visid;
    for(auto v:adj[u])
        if(!vis[v])
            dfs(v);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        visid++;
        if(!vis[i])
            dfs(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(vis[i]==val[i])
            ans++;
    cout<<ans<<endl;
    return 0;
}
