#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d

const int nm = 1e4;

int n, c[nm], s = 0, num[nm], cursor;
vector<int> g[nm];

void dfs(int v, int p) {
	num[v] = c[cursor];
	cursor--;
	for (int nv : g[v]) {
		if (nv == p)
			continue;
		dfs(nv, v);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	sort(c, c + n);
	for (int i = 0; i < n - 1; i++)
		s += c[i];
	cursor = n - 1;
	dfs(0, 0);
	cout << s << endl;
	for (int i = 0; i < n; i++)
		cout << num[i] << (i < n - 1 ? " " : "\n");
}
