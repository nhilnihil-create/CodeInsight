#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxn = 1e5+7;

vector<int> adj[mxn];
int dp[mxn];

int dfs(int u) {
	if(dp[u] != -1) {
		return dp[u];
	}
	int h = 0;
	
	for(int v : adj[u]) {
		h = max(h, dfs(v));
	}
	
	return dp[u] = 1 + h;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dfs(i));
	}
	cout << (ans - 1) << "\n";
}
