#include <cstdio>

const int N = 2e5 + 10;
const int M = 4e5 + 10;

int hd[N], nxt[M], to[M], cnt;
int deg[N][2];
int n, m;
char col[N];
int q[N], qhd, qtl, vis[N];

inline void adde(int x, int y) {
	cnt++;
	to[cnt] = y; nxt[cnt] = hd[x]; 
	hd[x] = cnt;
}

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", col+1);
	for (int i = 1, x, y; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		adde(x, y);
		adde(y, x);
		deg[x][col[y] == 'B']++;
		deg[y][col[x] == 'B']++;
	}
	for (int i = 1; i <= n; ++i) {
		if (deg[i][0] == 0 || deg[i][1] == 0) vis[q[qtl++] = i] = 1;
	}
	while (qhd != qtl) {
		int x = q[qhd++];
		// printf("%d\n", x);
		// vis[x] = 1;
		for (int i = hd[x]; i; i = nxt[i]) if (!vis[to[i]]) {
			if (--deg[to[i]][col[x] == 'B'] == 0) {
				vis[to[i]] = 1;
				q[qtl++] = to[i];
			} 
		}
	}
	if (qtl == n) puts("No");
	else puts("Yes");
}
