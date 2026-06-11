#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] , pos[MAX] , vis[MAX] , comp[MAX] ;
int n , m ;
int id = 0 ;

vector< vector<int> >adj(MAX) ;

void dfs(int node)
{
	vis[node] = 1 ;
	comp[node] = id ;
	for(auto &child : adj[node])
	{
		if(vis[child] == 1)
			continue ;
		dfs(child) ;
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>m ;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin>>arr[i] ;
		pos[arr[i]] = i ;
	}
	for(int i = 0 ; i < m ; ++i)
	{
		int x , y ;
		cin>>x>>y ;
		adj[x].push_back(y) ;
		adj[y].push_back(x) ;
	}
	for(int i = 1 ; i <= n ; ++i)
	{
		if(vis[i] == 1)
			continue ;
		id++ ;
		dfs(i) ;
	}
	int ans = 0 ;
	for(int i = 1 ; i <= n ; ++i)
	{
		if(comp[i] == comp[pos[i]])
			ans++ ;
	}
	return cout<<ans<<"\n" , 0 ;
}		