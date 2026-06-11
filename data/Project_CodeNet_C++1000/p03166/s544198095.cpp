#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
int visited[100001];
int dp[100001];
void dfs(int node)
{
	dp[node] = 0;
	visited[node] = 1;
	for (auto child : g[node])
	{
		if (!visited[child])
		{
			dfs(child);
		}
		dp[node] = max(dp[node], 1 + dp[child]);
	}
}
int main()
{
	int n, m, i, j, k; cin >> n >> m;
	for (i = 0; i < m; i++) cin >> j >> k, g[j].push_back(k);
	memset(visited, 0, sizeof(visited));
	for (i = 1; i <= n; i++)
		if (!visited[i])
			dfs(i);
	int ans = 0;
	for (i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << endl;


}

