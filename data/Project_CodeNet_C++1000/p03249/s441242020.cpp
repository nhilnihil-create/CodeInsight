#include <bits/stdc++.h>

const int N = 100005;
typedef long long LL;

int n, head[N], nxt[N], size[N];
LL D[N];
std::pair<LL, int> d[N];

void no() {std::cout << "-1\n", std::exit(0);}

void link(int x, int y) {nxt[y] = head[x], head[x] = y;}
int find(LL x) {
	auto it = std::lower_bound(d + 1, d + n + 1, std::make_pair(x, 0));
	if (it->first != x) no();
	return it->second;
}
int dfs0(int x) {
	for (int i = head[x]; i; i = nxt[i])
		D[x] += dfs0(i) + size[i];
	return D[x];
}
void dfs1(int x) {
	for (int i = head[x]; i; i = nxt[i])
		D[i] = D[x] + (n - 2 * size[i]), dfs1(i);
}

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> d[i].first, d[i].second = i, size[i] = 1;
	std::sort(d + 1, d + n + 1);
	for (int i = n; i > 1; --i) {
		int p = d[i].second, f = find(d[i].first - (n - 2 * size[p]));
		size[f] += size[p], link(f, p);
	}
	dfs0(d[1].second), dfs1(d[1].second);
	for (int i = 1; i <= n; ++i)
		if (D[d[i].second] != d[i].first) no();
	for (int i = 1; i <= n; ++i)
		for (int j = head[i]; j; j = nxt[j]) std::cout << i << ' ' << j << '\n';
	return 0;
}