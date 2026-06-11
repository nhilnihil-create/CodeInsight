#include <cstdio>
#include <algorithm>
#include <numeric>
#include <map>
#define fail return puts("-1"), 0

const int N = 1e5 + 5, M = 2e5 + 5;

int n, tot, lnk[N], ter[M], nxt[M], sz[N], fa[N];
long long dep[N], d[N], D[N];
std::map<long long, int> mp;

void add(int u, int v) {
	ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot;
}
void dfs1(int u, int p) {
	sz[u] = 1;
	for (int i = lnk[u]; i; i = nxt[i]) {
		int v = ter[i];
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		dfs1(v, u);
		sz[u] += sz[v];
	}
}
void dfs2(int u, int p) {
	for (int i = lnk[u]; i; i = nxt[i]) {
		int v = ter[i];
		if (v == p) continue;
		D[v] = D[u] - 2 * sz[v] + n;
		dfs2(v, u);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		mp[d[i]] = i;
		sz[i] = 1;
	}
	int cnt = 0;
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		int v = it->second;
		long long now = it->first;
		long long s = now + 2 * sz[v] - n;
		if (!mp.count(s)) fail;
		int u = mp[s];
		if (u == v) fail;
		fa[v] = u, sz[u] += sz[v];
		add(u, v), add(v, u);
		if (++cnt == n - 1) break;
	}
	dfs1(1, 0);
	D[1] = std::accumulate(dep + 1, dep + n + 1, 0LL);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		if (D[i] != d[i]) fail;
	}
	for (int i = 1; i <= n; i++) {
		if (fa[i]) printf("%d %d\n", i, fa[i]);
	}
	return 0;
}