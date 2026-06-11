#include <bits/stdc++.h> 
using namespace std; 

void dfs(int node, vector<int> adj[], int dp[], bool vis[]) 
{ 
	vis[node] = true; 

	for (int i = 0; i < adj[node].size(); i++) { 

		if (!vis[adj[node][i]]) 
			dfs(adj[node][i], adj, dp, vis); 

		
		dp[node] = max(dp[node], 1 + dp[adj[node][i]]); 
	} 
} 


void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
} 


int findLongestPath(vector<int> adj[], int n) 
{ 
	// Dp array 
	int dp[n + 1]; 
	memset(dp, 0, sizeof dp); 
	bool vis[n + 1]; 
	memset(vis, false, sizeof vis);  
	for (int i = 1; i <= n; i++) { 
		if (!vis[i]) 
			dfs(i, adj, dp, vis); 
	} 

	int ans = 0; 
	for (int i = 1; i <= n; i++) { 
		ans = max(ans, dp[i]); 
	} 
	return ans; 
} 

 
int main() 
{ 
	int n, m;
	cin>>n>>m; 
	vector<int> adj[n + 1]; 
	int x,y;
	while(m--){
		cin>>x>>y;
		addEdge(adj, x, y);
	}


	cout << findLongestPath(adj, n); 
	return 0; 
} 
