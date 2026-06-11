//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000
#define MAXM 200000
vector<vector<int>> g;
int l[MAXM], r[MAXM], d[MAXM];

int n, m;

int input() {
	if (scanf("%d %d", &n, &m) < 0) return 0;
	g.resize(n);
	for (int i=0; i<m; i++) {
		scanf("%d %d %d", &l[i], &r[i], &d[i]);
		l[i]--, r[i]--;
		g[l[i]].push_back(i);
		g[r[i]].push_back(i);
	}
	return 1;
}

void init() {
}

long val[MAXN];
long maxv, minv;

int dfs(int v,int f) {
	for (auto e: g[v]) {
		int c = d[e], u = r[e];
		if (u == v) {
			c = -c;
			u = l[e];
		}
		long x = val[v] + c;
		if (val[u] != LONG_MAX) {
			if (val[u] != x) return 0;
			continue;
		}
		val[u] = x;
		minv = min(minv, x);
		maxv = max(maxv, x);
		if (!dfs(u, v)) return 0;
	}
	return 1;
}

long solve() {
	for (int i=0; i<n; i++)
		val[i] = LONG_MAX;
	for (int i=0; i<n; i++)
		if (val[i] == LONG_MAX) {
			maxv = minv = val[i] = 0;
			if (!dfs(i, -1)) return 0;
			if (maxv-minv > 1000000000) return 0;
		}
	//printa(val, n);
	return 1;
}

void output(long ans) {
	printf("%s\n", ans? "Yes":"No");
}

void cleanup() {
	g.clear();
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



