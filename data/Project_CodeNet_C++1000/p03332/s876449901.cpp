#include <bits/stdc++.h>
using namespace std;

const int maxn = 300005;
const long long mod = 998244353;

long long n, a, b, k, ans;
long long fact[maxn];

long long add_mod (long long x, long long y) {
	return (x + y) % mod;
}

long long mul_mod (long long x, long long y) {
	return (x * y) % mod;
}

long long pow_mod (long long x, long long y) {
	long long res = 1, t = x;
	while (y) {
		if (y & 1)
			res = mul_mod(res, t);
		t = mul_mod(t, t);
		y >>= 1;
	}
	return res;
}

long long div_mod (long long x, long long y) {
	return mul_mod(x, pow_mod(y, mod - 2));
}

long long ncr_mod (long long x, long long y) {
	return div_mod(fact[x], mul_mod(fact[x - y], fact[y]));
}

void precalc () {
	fact[0] = 1;
	for (long long i = 1; i < maxn; ++i)
		fact[i] = mul_mod(i, fact[i - 1]);
}

signed main () {
	precalc();
	scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
	for (long long i = 0; i <= n; ++i) {
		if ((k - i * a) >= 0 && (k - i * a) % b == 0 && 0 <= (k - i * a) / b && (k - i * a) / b <= n) 
			ans = add_mod(ans, mul_mod(ncr_mod(n, i), ncr_mod(n, (k - i * a) / b)));
	}
	printf("%lld\n", ans);
}
