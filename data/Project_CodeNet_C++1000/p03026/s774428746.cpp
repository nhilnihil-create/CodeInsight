#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
const LL MOD = 1e9 + 7;
int n, c[N], dep[N], ans[N];
vector<int> g[N], vec[N];
void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	vec[dep[u]].push_back(u);
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	long long s = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &c[i]); s += c[i];
	}
	sort(c + 1, c + 1 + n); s -= c[n];
	dfs(1, 1);
	for (int i = n, j = 1; i >= 1; i --) {
		for (auto x: vec[i]) {
			ans[x] = c[j ++];
		}
	}
	printf("%lld\n", s);
	for (int i = 1; i <= n; i ++) {
		printf("%d ", ans[i]);
	}
}	
