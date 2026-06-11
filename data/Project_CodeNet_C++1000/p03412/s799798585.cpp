#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
constexpr long long MOD(long long in) {
	return in % mod;
}


int n;
int main()
{
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	for (int i = 0; i < n; ++i)
		std::cin >> b[i];

	int ans = 0;
	for (int i = 0; i < 29; ++i) {
		int x = 1 << i;
		std::vector<int> v(n);
		for (int j = 0; j < n; ++j)
			v[j] = b[j] % (x << 1);
		std::sort(v.begin(), v.end());

		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			int c = a[j] % (x << 1);
			std::vector<int> y = { x, x << 1, (x << 1) | x };
			std::vector<int> index(3);
			for (int k = 0; k < 3; ++k)
				index[k] = std::lower_bound(v.begin(), v.end(), y[k] - c) - v.begin();
			cnt += (index[1] - index[0]) + (n - index[2]);
		}
		if (cnt % 2 != 0)
			ans ^= x;
	}
	std::cout << ans << std::endl;

	return 0;
}
