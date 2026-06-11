#include <cstdio>
#include <algorithm>
#include <numeric>
#include <map>
#define fail return puts("-1"), 0

const int N = 1e5 + 5, M = 2e5 + 5;

int n, tot, lnk[N], ter[M], nxt[M], sz[N];
long long dis[N], d[N];
std::map<long long, int> mp;

void add(int u, int v) {
	ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot;
}
void dfs(int u, int p) {
	for (int i = lnk[u]; i; i = nxt[i]) {
		int v = ter[i];
		if (v == p) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &d[i]);
		mp[d[i]] = i, sz[i] = 1;
	}
	int cnt = 0;
	for (auto it = mp.rbegin(); it != mp.rend(); it++) {
		int v = it->second, u = mp[it->first + 2 * sz[v] - n];
		if (!u || u == v) fail;
		add(u, v), add(v, u), sz[u] += sz[v];
		if (++cnt == n - 1) break;
	}
	int rt = mp.begin()->second;
	dfs(rt, 0);
	if (std::accumulate(dis + 1, dis + n + 1, 0LL) != d[rt]) fail;
	for (int i = 1; i <= tot; i += 2) {
		printf("%d %d\n", ter[i], ter[i + 1]);
	}
	return 0;
}