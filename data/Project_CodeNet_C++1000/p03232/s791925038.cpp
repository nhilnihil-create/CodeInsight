#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n, m;
int a[N];
ll ans, fac[N], inv[N], sum[N];
ll Pow(ll a, int x) {
	ll res = 1;
	while (x) {
		if (x & 1) (res *= a) %= mod;
		(a *= a) %= mod;
		x >>= 1;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		sum[i] = sum[i - 1] + a[i];
		sum[i] %= mod;
	}
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
	for (int i = 1; i < n; ++i) {
		ll tmp = fac[n] * Pow(i + 1, mod - 2) % mod;
		(ans += tmp * (sum[n - i] + sum[n] - sum[i])) %= mod;
	}	
	(ans += sum[n] * fac[n]) %= mod;
	cout << ans;
} 