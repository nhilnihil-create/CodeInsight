#include <cstdio>

int n, m, L;

struct Edge {
	Edge() {}
	Edge(int _u, int _v, int _w) {
		u = _u, v = _v, w = _w;
	}
	int u, v, w;
} e[65];

void add(int u, int v, int w) {
	e[++m] = Edge(u, v, w);
}
int main() {
	scanf("%d", &L);
	for (; (1 << n) - 1 < L; n++);
	for (int i = 1; i < n; i++) {
		add(i, i + 1, 1 << (i - 1));
		add(i, i + 1, 0);
	}
	for (int i = 1; i < n; i++) {
		if (L & (1 << (i - 1))) add(i, n, (L >> i) << i);
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; i++) {
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
	}
	return 0;
}