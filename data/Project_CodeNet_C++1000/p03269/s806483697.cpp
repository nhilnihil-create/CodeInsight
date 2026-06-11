#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30, MAXM = 80;
int L, n, m, pw;

struct Edge {
	int u, v, w;
	Edge() {}
	Edge(int _, int __, int ___) {
		u = _, v = __, w = ___;
	}
} edge[MAXM];

int main() {
	scanf("%d", &L);
	for (pw = 1, n = 0; pw <= L; pw <<= 1, ++n);
	for (int i = 1; i < n; ++i) {
		edge[++m] = Edge(i, i + 1, 1 << i - 1);
		edge[++m] = Edge(i, i + 1, 0);
	}
	int sum = 1 << n - 1;
	for (int i = n - 1; i; --i)
		if (L & (1 << i - 1)) {
			edge[++m] = Edge(i, n, sum);
			sum += 1 << i - 1;
		}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= m; ++i) printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].w);
	return 0;
}