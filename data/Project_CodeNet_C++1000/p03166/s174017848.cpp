#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001];
int dp[100001];

#define pb push_back

void dfs(int node)
{
	vis[node] = 1;
	dp[node] = 0;
	
	for(int child : adj[node])
	{
		if(vis[child] == 0)
			dfs(child);
			
		dp[node] = max(dp[node], dp[child] + 1);
	}
}

int main() {
	// your code goes here
	
	int n, m;
	cin >> n >> m;
	
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(vis[i] == 0)
			dfs(i);
	}
	int ans =0;
	for(int i = 1; i <= n; i++)
	{
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
	return 0;
}