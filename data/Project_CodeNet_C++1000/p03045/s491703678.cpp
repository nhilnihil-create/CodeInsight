#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&visited,vector<vector<int> >&adj)
{
	for(auto var:adj[node])
	{
		if(visited[var])
		 continue;
		visited[var]=1;
		dfs(var,visited,adj);
	}
	
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> >adj(n+1);
	for(int i=1; i<=m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int>visited(n+1);
	int ans=0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			ans++;
			visited[i]=1;
			dfs(i,visited,adj);
		}
	}
	cout<<ans;
	return 0;
}