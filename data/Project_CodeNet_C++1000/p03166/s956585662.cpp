#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

int n, m;
vector<vector<int>> graph;
vector<int> dp;
vector<bool> vis;

int dfs(int u){
	if(dp[u] != -1) return dp[u];
	vis[u] = 1;
	int ans = 0;
	for(int v : graph[u]){
		ans = max(ans, 1 + dfs(v));
	}
	return dp[u] = ans;
}

void solution(){
	cin >> n >> m;
	graph = vector<vector<int>>(n);
	dp = vector<int>(n,-1);
	vis = vector<bool>(n,0);
	for(int i = 0; i < m; i++){
		int u,v; cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	cout << *max_element(all(dp)) << endl;
}	


int main(){ 
	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}