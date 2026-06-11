#include <bits/stdc++.h>

typedef long long LL;
const int N = 1005, K = 30;

std::vector<LL> v;
LL n, x[N], y[N];

void solve(LL x, LL y, int dep) {
	if (dep == v.size()) return void(std::cout << '\n');
	if (std::abs(x) > std::abs(y))
		if (x < 0) x += v[dep], std::cout << 'R';
		else x -= v[dep], std::cout << 'L';
	else
		if (y < 0) y += v[dep], std::cout << 'U';
		else y -= v[dep], std::cout << 'D';
	solve(x, y, dep + 1);
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i] >> y[i];
		if ((x[i] ^ x[1] ^ y[i] ^ y[1]) & 1)
			return std::cout << "-1\n", 0;
	}
	for (int i = K; ~i; --i) v.push_back(1LL << i);
	if ((x[1] ^ y[1] ^ 1) & 1) v.push_back(1);
	std::cout << v.size() << '\n';
	for (LL i : v) std::cout << i << ' ';
	std::cout << '\n';
	for (int i = 1; i <= n; ++i) solve(-x[i], -y[i], 0);
	return 0;
}