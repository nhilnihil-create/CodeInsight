#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;
const int MN = 100005;

int N, p[MN], siz[MN], ok;
LL dis[MN], sum[MN];
bool cmp(int i, int j) { return dis[i] > dis[j]; }
std::vector<int> G[MN];

void DFS(int u, LL d) {
	if (d != dis[u]) ok = 0;
	for (auto v : G[u]) DFS(v, d + N - 2 * siz[v]);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%lld", &dis[i]), p[i] = i, siz[i] = 1;
	std::sort(p + 1, p + N + 1, cmp);
	for (int i = 1; i < N; ++i) {
		int u = p[i];
		if (2 * siz[u] >= N) return puts("-1"), 0;
		dis[0] = dis[u] - N + 2 * siz[u];
		int pos = std::lower_bound(p + i + 1, p + N + 1, 0, cmp) - p;
		if (pos > N) return puts("-1"), 0;
		int v = p[pos];
		G[v].push_back(u);
		siz[v] += siz[u];
		sum[v] += sum[u] + siz[u];
	}
	ok = 1;
	DFS(p[N], sum[p[N]]);
	if (!ok) return puts("-1"), 0;
	for (int i = 1; i <= N; ++i)
		for (auto v : G[i]) printf("%d %d\n", i, v);
	return 0;
}