#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector <int> kid[N];
int n, m, rt;
int res[N], dad[N];

void solve(int v) {
	for (auto u: kid[v])
		dad[u]--;
	for (auto u: kid[v])
		if (!dad[u] && !res[u])
			res[u] = v, solve(u);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n + m - 1; i++) {
		int u, v;
		cin >> u >> v;
		kid[u].push_back(v);
		dad[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (!dad[i])
			rt = i;
	solve(rt);
	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;
	return 0;
}
