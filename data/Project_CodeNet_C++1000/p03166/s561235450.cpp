#include<bits/stdc++.h>
using namespace std;
#define ll long long

int cur=0;
int a=0;
int dp[100009];

int dfs(int u, vector<int> adj[]){
	if(dp[u] != -1)
		return dp[u];
		
	int cur=0;
	
	for(auto v : adj[u]){
		cur = max (cur, dfs(v, adj)+1);
	}
	
	return dp[u]=cur;
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	int x, y;	
	while(m--) {
		cin >> x >> y;
		adj[x].push_back(y);		
	}
	int ans=0;
	memset(dp, -1, sizeof dp);
	
	for(int i=1; i<=n; i++){
		ans=max(ans, dfs(i, adj));
	}
	
	cout << ans << "\n";
}

int main(){
	solve();
}
