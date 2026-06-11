#include <iostream>
#include <algorithm>
#include <cstdio>
const int maxn = 1010,
	X[] = { 1, 0, -1, 0 }, Y[] = { 0, 1, 0, -1 };

int n, x[maxn], y[maxn], w[maxn], idx;
void solve(long long x, long long y) {
	for (int i = 1; i <= idx; ++i) {
		char c;
		if (abs(x) > abs(y))
			if (x < 0) x += w[i], c = 'L';
			else x -= w[i], c = 'R';
		else
			if (y < 0) y += w[i], c = 'D';
			else y -= w[i], c = 'U';
		std::cout << c;
	}
	std::cout.put('\n');
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> x[i] >> y[i];
		if ((x[i] + y[i] & 1) != (x[1] + y[1] & 1)) {
			std::cout << "-1\n";
			return 0;
		}
	}
	for (int i = 30; ~i; --i) w[++idx] = 1 << i;
	if (!(x[1] + y[1] & 1)) w[++idx] = 1;
	std::cout << idx << '\n';
	for (int i = 1; i < idx; ++i) std::cout << w[i] << ' ';
	std::cout << w[idx] << '\n';
	for (int i = 1; i <= n; ++i) solve(x[i], y[i]);
	return 0;
}
