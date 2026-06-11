#include <bits/stdc++.h>

void bye() { std::cout << -1 << std::endl; exit(0); }
const int MAXN = 100010;
typedef long long LL;
std::map<LL, LL> idx, sub, fa, dep;
int n;
LL D[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> D[i], idx[D[i]] = i, sub[D[i]] = 1;
	std::sort(D + 1, D + 1 + n);
	for (int i = n; i > 1; --i) {
		LL td = D[i] - n + sub[D[i]] * 2;
		if (td >= D[i] || !idx.count(td)) bye();
		sub[td] += sub[D[i]];
		fa[D[i]] = td;
	}
	for (int i = 2; i <= n; ++i) {
		dep[D[i]] = dep[fa[D[i]]] + 1;
		D[1] -= dep[D[i]];
	}
	if (D[1]) bye();
	for (int i = 2; i <= n; ++i)
		std::cout << idx[fa[D[i]]] << ' ' << idx[D[i]] << '\n';
	return 0;
}
