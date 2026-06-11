#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d

const int nm = 1e5 - 1;
int n, m, p[nm], d[nm];
vector<int> g[nm];
bool b[nm];

void dfs(int v) {
	if (g[v].empty()) {
		p[v] = -1;
		d[v] = 0;
	} else {
		for (int nv : g[v]) {
			if (!b[nv])
				dfs(nv);
			if (d[nv] + 1 > d[v]) {
				d[v] = d[nv] + 1;
				p[v] = nv;
			}
		}
	}
	b[v] = 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n - 1 + m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		if (!b[i])
			dfs(i);
	for (int i = 0; i < n; ++i)
		cout << p[i] + 1 << endl;
}
