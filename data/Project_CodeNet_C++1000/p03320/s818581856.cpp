#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr int iinf = static_cast<int>(1e9);
constexpr ll mod = static_cast<ll>(1e9 + 7);
constexpr long long MOD(long long in) {
	return in % mod;
}

ll k;
ll f(ll n) {
	long double calc = inf;
	ll ans = 0;
	for (int d = 0, end = std::log10(n) + 1; d <= end; d++) {
		ll p = std::pow(10, d);
		ll num = (n / p) * p + (p * 10 - 1);

		ll tmp = num;
		ll sum = 0;
		while (tmp != 0) {
			sum += tmp % 10;
			tmp /= 10;
		}

		long double tmp2 = ((long double)num) / sum;
		if (calc > tmp2) {
			calc = tmp2;
			ans = num;
		}
	}

	return ans;
}

int main()
{
	std::cin >> k;

	for (int i = 1; i < 10 && k; i++, k--)
		std::cout << i << std::endl;

	ll n = 9;
	for (int i = 0; i < k; i++) {
		n = f(n + 1);
		std::cout << n << std::endl;
	}

	return 0;
}
