#include <cstdio>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
int fa[100010];
vector <int> v[100010], vf[100010];

int find_root(int u) {
	if (!fa[u] || fa[u] == u) return u;
	return fa[u] = find_root(fa[u]);
}

void merge(int a, int b) {
	int ra = find_root(a), rb = find_root(b);
	if (ra != rb) fa[ra] = rb;
}

int main() {
	int n, m;
	ll ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < v[i].size(); ++j)
			merge(v[i][j], v[i][j - 1]);
	}
	for (int i = 1; i <= n; ++i) {
		fa[i] = find_root(i);
		vf[fa[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		if (fa[i] == i) {
			set <int> s;
			for (auto k : vf[i])
				for (auto j : v[k])
					s.insert(j);
			ans += 1ll * vf[i].size() * s.size();
			for (auto k : vf[i])
				if (s.count(k)) --ans;
		}
	printf("%lld\n", ans / 2 - m);
	return 0;
}
