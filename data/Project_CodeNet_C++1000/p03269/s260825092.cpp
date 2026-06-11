#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w;
	edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int l; cin >> l;
	int n = 32 - __builtin_clz(l);
	vector<edge> g;
	int u = 1;
	for (int i = 1; i < n; i++) {
		g.emplace_back(i, i + 1, u);
		g.emplace_back(i, i + 1, 0);
		u <<= 1;
	}
	for (int i = 0; i < n - 1; i++) {
		if (l >> i & 1) {
			g.emplace_back(i + 1, n, l >> (i + 1) << (i + 1));
		}
	}
	cout << n << ' ' << g.size() << endl;
	for (auto e : g) {
		cout << e.u << ' ' << e.v << ' ' << e.w << "\n";
	}
	return 0;
}
