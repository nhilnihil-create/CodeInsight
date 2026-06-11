#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[100000];
vector<int> dist(100000, -1);
void bfs(int st) {
	dist[st] = 0;
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int n = q.front();
		for (auto v : g[n]) {
			if (dist[v.first] == -1) {
				dist[v.first] = dist[n] + v.second;
				q.push(v.first);
			}
		}
		q.pop();
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	bfs(0);
	for (int i = 0; i < n; i++) {
		if (dist[i] % 2 == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}
	return 0;
}