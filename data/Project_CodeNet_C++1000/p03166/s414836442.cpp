#include<bits/stdc++.h>
using namespace std;
int n, m, x, y;
int dp[100005];
vector<bool> visited(100005, false);
vector<int> adj_list[100005];

void dfs(int src) {
	visited[src] = 1;

	for (int i = 0; i < adj_list[src].size(); i++) {
		int child = adj_list[src][i];
		if (!visited[child]) {
			dfs(child);
		}
		dp[src] = max(dp[src], dp[child] + 1);
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj_list[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	int max_path_len = -1;
	for (int i = 1; i <= n; i++) {
		max_path_len = max(dp[i], max_path_len);
	}

	cout << max_path_len << endl;
	return 0;
}