#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef long long int ll;

vector<int> adj[100000], dp;

int dfs(int curr, vector<bool>& visited) {
	if (visited[curr])
		return dp[curr];
	visited[curr] = true;
	int max_val = 0;
	for (int node : adj[curr]) {
		max_val = max(max_val, 1 + dfs(node, visited));
	}
	return dp[curr] = max_val;
}


int main() {
	fastio;
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
	}
	dp.resize(n + 1);
	vector<bool> visited(n + 1);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			res = max(res, dfs(i, visited));
		}
	}
	cout << res;
	return 0;
}