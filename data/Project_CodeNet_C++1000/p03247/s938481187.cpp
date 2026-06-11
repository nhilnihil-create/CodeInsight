#include <bits/stdc++.h>

const int MAXN = 1010;
typedef long long LL;
int xs[MAXN], ys[MAXN], n;
char step[50];
const int UP = 39;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> xs[i] >> ys[i];
	for (int i = 1; i <= n; ++i)
		if ((xs[i] + ys[i] & 1) != (xs[1] + ys[1] & 1))
			return std::cout << -1 << std::endl, 0;
	int typ = (xs[1] + ys[1] & 1) ^ 1;
	std::cout << UP + typ << '\n';
	if (typ) std::cout << 1 << ' ';
	for (int i = 0; i < UP; ++i)
		std::cout << (1ll << i) << (" \n" [i == UP - 1]);
	for (int i = 1; i <= n; ++i) {
		LL x = xs[i], y = ys[i];
		if (typ) step[0] = 'L', ++x;
		int cur = typ + UP - 1;
		for (int j = UP - 1; ~j; --j, --cur) {
			const LL L = 1ll << j;
			if (std::abs(x) > std::abs(y)) {
				if (x > 0) step[cur] = 'R', x -= L;
				else step[cur] = 'L', x += L;
			} else {
				if (y > 0) step[cur] = 'U', y -= L;
				else step[cur] = 'D', y += L;
			}
		}
		std::cout << step << '\n';
	}
	return 0;
}
