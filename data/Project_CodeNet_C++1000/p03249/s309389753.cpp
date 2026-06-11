#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pli pair<LL, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 100005;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

void gg() {
	puts("-1");
	exit(0);
}

int n, siz[MAXN];
pli p[MAXN];
vector<int> e[MAXN];
LL sum[MAXN];

void DFS1(int u) {
	for (auto v : e[u]) {
		DFS1(v);
		sum[u] += sum[v] + siz[v];
	}
}

void DFS2(int u) {
	for (auto v : e[u]) {
		sum[v] = sum[u] + n - siz[v] * 2;
		DFS2(v);
	}
}

void init() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(p[i].fi);
		p[i].se = i;
	}
	sort(p + 1, p + n + 1);
}

void solve() {
	for (int i = n; i > 1; --i) {
		int u = p[i].se;
		siz[u] += 1;
		LL fd = p[i].fi - (n - siz[u] * 2);
		int j = lower_bound(p + 1, p + n + 1, MP(fd, 0)) - p;
		if (j >= i || p[j].fi != fd) gg();
		int fa = p[j].se;
		siz[fa] += siz[u];
		e[fa].push_back(u);
	}
	siz[p[1].se] += 1;
	DFS1(p[1].se);
	DFS2(p[1].se);
	for (int i = 1; i <= n; ++i) {
		if (sum[p[i].se] != p[i].fi) gg();
	}
	for (int u = 1; u <= n; ++u) {
		for (auto v : e[u]) {
			printf("%d %d\n", u, v);
		}
	}
}

int main() {
	init();
	solve();
	return 0;
}

