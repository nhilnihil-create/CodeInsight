#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	m += (n - 1);
	vector<int> in(n);
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		in[v]++;
	}
	vector<int> p(n, -1);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : g[v]) {
			in[u]--;
			if (!in[u]) {
				p[u] = v;
				q.push(u);
			}
		}
	}
	for (auto t : p) {
		cout << t + 1 << '\n';
	}
}
