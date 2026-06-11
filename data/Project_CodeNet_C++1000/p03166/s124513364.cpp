#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;
#define ll long long int
#define maxn 100005

void _init() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


vector<int> adj[maxn];


vector<int> dist(maxn, 0);
vector<int> indegree(maxn, 0);
vector<bool> vis(maxn, 0);

void dfs(int i) {
	vis[i] = 1;
	for (int x : adj[i]) {
		dist[x] = max(dist[x], 1 + dist[i]);
		indegree[x]--;
		if (indegree[x] == 0)dfs(x);
	}
}

int main() {
	_init();

	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		++indegree[b];
	}

	int maxDepth = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i] && indegree[i] == 0)
		{
			dfs(i);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		maxDepth = max(maxDepth, dist[i]);
	}

	cout << maxDepth << endl;

	return 0;
}







