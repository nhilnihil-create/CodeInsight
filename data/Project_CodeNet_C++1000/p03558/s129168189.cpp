#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int k;
// 頂点i : kで割って(i-1)余る整数
vector<vector<pair<int, int>>> g;

void construct() {
	g.resize(k + 1);
	g[0].push_back(make_pair(2, 1));
	for (int i = 1; i <= k; ++i)
		g[i].push_back(make_pair(i % k + 1, 1));
	for (int i = 1; i <= k; ++i) 
		g[i].push_back(make_pair((i - 1) * 10 % k + 1, 0));
	return;
}

template<typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>>& G) {
	const int n = G.size();
	vector<T> d(n, numeric_limits<T>::max());
	vector<int> b(n, -1);
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> q;
	d[s] = 0;
	q.emplace(d[s], s);
	while (!q.empty()) {
		pair<T, int> p = q.top();
		q.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (auto& e : G[v]) {
			int u = e.first;
			T c = e.second;
			if (d[u] > d[v] + c) {
				d[u] = d[v] + c;
				b[u] = v;
				q.emplace(d[u], u);
			}
		}
	}
	return d;
}

int main() {
	cin >> k;
	construct();
	vector<int> res = dijkstra(0, g);
	cout << res[1] << endl;
	return 0;
}