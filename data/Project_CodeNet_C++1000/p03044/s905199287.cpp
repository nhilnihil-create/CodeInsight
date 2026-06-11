#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void dfs(int node,int parent,vector<vector<pair<int,ll> > >&adj,vector<ll>&dist)
{
	for(auto var : adj[node])
	{
		if(var.first!=parent){
			dist[var.first]=dist[node]+var.second;
			dfs(var.first,node,adj,dist);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<vector<pair<int,ll> > >adj(n+1);
	for(int i=1; i<n; i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
    vector<ll>dist(n+1);
    dfs(1,0,adj,dist);
    vector<int>color(n+1);
    for(int i=1; i<=n; i++){
    	if(dist[i]%2==0)
    	 color[i]=1;
    	else
    	 color[i]=0;
	}
	for(int i=1; i<=n; i++)
	 cout<<color[i]<<"\n";
	return 0;
}