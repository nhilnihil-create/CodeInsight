#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n, a, b, l, u_n;
vector < int > g[maxn];

void dfs_mx (int u, int p, int lvl) {
	if (lvl >= l)
		l = lvl, u_n = u;
	for (int v: g[u]) {
		if (v != p) 
			dfs_mx(v, u, lvl + 1);
	}
}

signed main () {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs_mx(1, -1, 0);
	dfs_mx(u_n, -1, 0);
	if (l % 3 == 1)
		printf("Second\n");
	else
		printf("First\n");
}
