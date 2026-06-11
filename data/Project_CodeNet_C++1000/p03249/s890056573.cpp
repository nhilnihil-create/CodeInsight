#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int> pr;
const int N = 100054;

int n;
int o[N], size[N];
int p[N], fc[N], nc[N];
ll D[N];
std::vector <pr> edges;

inline bool Dcmp(const int x, const int y) {return D[x] > D[y];}

inline bool find(ll x, int &ret) {return *D = x, ret = std::lower_bound(o, o + n, 0, Dcmp) - o, D[o[ret]] == x;}

inline void link(int x, int px) {p[x] = px, nc[x] = fc[px], fc[px] = x, size[px] += size[x];}

void dfs(int x, int d) {*D += d; for (int y = fc[x]; y; y = nc[y]) dfs(y, d + 1);}

int main() {
	int i, j, u;
	scanf("%d", &n), std::iota(o, o + n, 1);
	for (i = 1; i <= n; ++i) scanf("%lld", D + i);
	std::sort(o, o + n, Dcmp), std::fill(size + 1, size + (n + 1), 1);
	for (i = 0; i < n - 1; link(u, o[j]), ++i)
		if (u = o[i], !find(D[u] + 2 * size[u] - n, j) || j <= i) return puts("-1"), 0;
	if (dfs(o[i], *D = 0), *D != D[o[i]]) return puts("-1"), 0;
	for (i = 1; i <= n; ++i) if (p[i]) edges.EB(std::minmax(i, p[i]));
	std::sort(edges.begin(), edges.end());
	for (const pr &e : edges) printf("%d %d\n", e.first, e.second);
	return 0;
}