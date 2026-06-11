#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
long long d[N];
priority_queue <pair <long long, int> > pq;
int siz[N];
int fa[N];
map <long long, set <int> > mp;
vector <int> g[N];

#define NO() return puts("-1"), 0

long long dfs(int u) {
	long long ans = 0;
	for (int i = 0; i < g[u].size(); ++ i)
		ans += dfs(g[u][i]) + siz[g[u][i]];
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i)
		scanf("%lld", &d[i]), mp[d[i]].insert(i),
		siz[i] = 1, pq.push(make_pair(d[i], i));
	int rt;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop(); mp[d[u]].erase(u);
		if (!pq.empty()) {
			long long fa_d = (d[u] - (n - 2 * siz[u]));
//			printf("%d %lld %lld\n", u + 1, d[u], fa_d);
			if (!mp[fa_d].size()) NO();
			int v = *mp[fa_d].begin();
			fa[u] = v;
			g[v].push_back(u);
			siz[v] += siz[u];
		} else fa[u] = -1, rt = u;
	}
	if (dfs(rt) != d[rt]) NO();
	for (int i = 0; i < n; ++ i)
		if (~fa[i]) printf("%d %d\n", fa[i] + 1, i + 1);
	return 0;
}