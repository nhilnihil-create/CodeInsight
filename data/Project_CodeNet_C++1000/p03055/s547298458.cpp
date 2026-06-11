#include <cstdio>
#include <iostream>

using namespace std;

int n;

int head[200010], to[400010], nxt[400010], cnt;

inline void AddEdge (int u, int v) { ++cnt, to[cnt] = v, nxt[cnt] = head[u], head[u] = cnt; }

int mxu = 1, mxl;

inline void Dfs (int u, int p, int dis) {
	if (dis > mxl) mxl = dis, mxu = u;
	for (int e = head[u]; e; e = nxt[e]) {
		int v = to[e];
		if (v == p) continue;
		Dfs (v, u, dis + 1);
	}
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i < n; ++i) {
		int u, v; scanf ("%d%d", &u, &v);
		AddEdge (u, v), AddEdge (v, u);
	}
	
	Dfs (1, 0, 0);
	
	mxl = 0, Dfs (mxu, 0, 0);
	
	if (mxl % 3 == 1) printf ("Second\n");
	else printf ("First\n");
	
	return 0;
}