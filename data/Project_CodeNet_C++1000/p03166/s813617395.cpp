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


vector<int> dist(maxn, -1);

int dfs(int i) {
	if (dist[i] != -1)return dist[i];

	int maxDepth = INT_MIN;
	for (auto x : adj[i]) {
		maxDepth = max(maxDepth, 1 + dfs(x));
	}

	return dist[i] = maxDepth == INT_MIN ? 0 : maxDepth;
}

int main() {
	_init();

	int n, m;
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b, a--, b--;
		adj[a].push_back(b);
	}

	int maxDepth = 0;
	for (int i = 0; i < n; i++) {
		maxDepth = max(maxDepth, dfs(i));
	}

	cout << maxDepth << endl;

	return 0;
}







