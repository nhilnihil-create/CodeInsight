#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int ll;

vector<int> adj[100000], dp;

void dfs(int curr, vector<bool>& visited) {
	visited[curr] = true;
	for (int node : adj[curr]) {
		if (!visited[node]) {
			dfs(node, visited);
		}
		dp[curr] = max(dp[curr], dp[node] + 1);
	}
}


int main() {
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
			dfs(i, visited);
		}
	}
	for (int i = 1; i <= n; i++)
		res = max(dp[i], res);
	cout << res;
	return 0;
}