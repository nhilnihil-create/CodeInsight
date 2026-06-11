#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll long long
#define par pair<ll, int>

int n;
par a[N];
int Fa[N];
int sz[N], uf[N], d[N];
vector<pair<int, int>> E;

int find(int x) {
	return uf[x] == x ? x : (uf[x] = find(uf[x]));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i].first);
		a[i].second = i;
		sz[i] = 1;
		uf[i] = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = n; i > 1; i--) {
		ll d = a[i].first;
		int p = a[i].second;
		int fa = lower_bound(a + 1, a + n + 1, par(d - n + (sz[p] << 1), 0)) - a;
		if (a[fa].first != d - n + (sz[p] << 1)) {
			puts("-1");
			return 0;
		}
		if (find(p) == find(fa = a[fa].second)) {
			puts("-1");
			return 0;
		}
		sz[fa] += sz[p];
		E.emplace_back(p, fa);
		Fa[p] = fa;
	}
	ll f1 = 0;
	for (int i = 2; i <= n; i++)
		f1 += (d[a[i].second] = d[Fa[a[i].second]] + 1);
	if (f1 ^ a[1].first) {
		puts("-1");
		return 0;
	}
	for (auto x : E)
		printf("%d %d\n", x.first, x.second);
	return 0;
}
