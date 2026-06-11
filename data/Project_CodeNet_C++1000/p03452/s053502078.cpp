#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
vector< pair<ll,ll> > adj[N];
ll vis[N],dist[N],n,m;
void dfs(ll u,ll d)
{
    if(vis[u]==1)
	{
        if(dist[u]!=d)
		{
            cout<<"No";
            exit(0);
        }
        return;
    }
    vis[u]=1;
    dist[u]=d;
    for(auto node:adj[u])
		dfs(node.first,d+node.second);
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0;i<m;i++)
	{
        ll x,y,d;
		cin>>x>>y>>d;
        adj[x].push_back({y,d});
        adj[y].push_back({x,-d});
    }
    for(ll i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,0);
    cout<<"Yes";
}