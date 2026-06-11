#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<vector<pair<int, int>>> G(n);
	int root = -1;
	for (int i = 0; i < n-1; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		G[u-1].push_back(make_pair(v-1, w));
		G[v-1].push_back(make_pair(u-1, w));
		if (w%2 == 1)
			root = u-1;
	}
	if (root == -1) {
		for (int i = 0; i < n; i++)
			cout << 0 << endl;
		return 0;
	}
	queue<int> q;
	vector<bool> visited(n, false);
	vector<int> colors(n, -1);
	vector<long long> w(n);
	colors[root] = 0;
	w[root] = 0;
	q.push(root);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (visited[v])
			continue;
		visited[v] = true;
		if (w[v]%2 == 1) {
			colors[v] = 1;
		} else {
			colors[v] = 0;
		}
		for (auto e : G[v]) {
			if (!visited[e.first]) {
				q.push(e.first);
				w[e.first] = w[v] + e.second;
			}
		}
	}
	for (auto e : colors) {
		cout << e << endl;
	}


	return 0;
}