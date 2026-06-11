#include <bits/stdc++.h>
#define R register
typedef unsigned long long ull;

const int MN = 2e5 + 5;

ull s[MN], x, ans = 0xffffffffffffffffull;

int n;

int main() {
	std::ios::sync_with_stdio(false);

	std::cin >> n >> x;
	for (R int i = 1, v; i <= n; ++i) {
		std::cin >> v;
		s[i] = s[i - 1] + v;
	}

	for (R int i = 1; ; ++i) {
		if ((i << 1) >= n) {
			ans = std::min(ans, x * i + 5 * s[n]);
			break;
		}
		R ull res = x * i, k = 7;
		res += 5 * (s[n] - s[n - (i << 1)]);
		for (R int j = n - (i << 1); ; k += 2, j -= i) {
			if (j <= i) {
				res += k * s[j];
				break;
			}
			res += (s[j] - s[j - i]) * k;
		}
		ans = std::min(ans, res);
	}
	
	std::cout << ans + x * n;

	return 0;
}