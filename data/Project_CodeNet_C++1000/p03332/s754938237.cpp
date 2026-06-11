#include<iostream>
using namespace std;
typedef long long ll;
const ll maxn = 3e6, mod = 998244353;
ll n, a, b, k;
ll numa, numb, ans = 0;
ll f[maxn + 1], inv[maxn + 1];

ll qpow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return ret;
}
ll C(int n, int m) {
	if (n < m) return 0;
	return f[n] * inv[m] % mod * inv[n - m] % mod;
}
void init() {
	f[0] = 1;
	for (ll i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % mod;
	}
	inv[n] = qpow(f[n], mod - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % mod;
}

int main() {
	cin >> n>> a >>b >> k;
	if (k == 0) { 
		cout << 1 << endl;
		return 0;
	}
	init();
	for (numa = 0; numa <= n && numa * a <= k; numa++) {
		if ((k - numa * a) % b != 0) continue;
		numb = (k - numa * a) / b;
		if (numb > n) continue;
		ans = (ans + C(n, numa) * C(n, numb)) % mod;
	}
	printf("%lld", ans);
	return 0;
}
