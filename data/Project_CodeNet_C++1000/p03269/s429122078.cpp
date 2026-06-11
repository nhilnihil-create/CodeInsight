#include <cstdio>

int n, m, L;

struct Edge {
	int u, v, w;
	Edge(int _u = 0, int _v = 0, int _w = 0) {
		u = _u, v = _v, w = _w;
	}
} e[65];

void add(int u, int v, int w) {
	e[++m] = Edge(u, v, w);
}
int main() {
	scanf("%d", &L);
	for (; (1 << n) <= L; n++);
	for (int i = 1; i < n; i++) {
		add(i, i + 1, 1 << (i - 1));
		add(i, i + 1, 0);
	}
	int v = 1 << (n - 1);
	for (int i = n - 1; i >= 1; i--) {
		if (v + (1 << (i - 1)) - 1 < L) {
			add(i, n, v);
			v += 1 << (i - 1);
		}
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
	}
	return 0;
}