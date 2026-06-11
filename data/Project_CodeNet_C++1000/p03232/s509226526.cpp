#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())

typedef long long ll;

int const MOD = 1e9 + 7;

ll KSM(ll a, ll k) {
	ll ret = 1;
	for(; k; k >>= 1) {
		if(k & 1) 
			ret = ret * a % MOD;
		a = a * a % MOD;
	}
	return ret;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> inv(n + 1);
	for(int i = 0; i < n; ++i) 
		std::cin >> a[i];
	for(int i = 1; i <= n; ++i) 
		inv[i] = KSM(i, MOD - 2);
	ll C = 0;
	for(int i = 1; i <= n; ++i)
		(C += inv[i]) %= MOD;
	ll ans = 0;
	for(int i = 0; i < SZ(a); ++i) {
		ans = (ans + C * a[i] % MOD) % MOD;
		C += inv[i + 2];
		C -= inv[n - i];
		C = (C % MOD + MOD) % MOD;
	}
	for(int i = 1; i <= n; ++i) 
		ans = ans * i % MOD;
	ans = (ans % MOD + MOD) % MOD;
	std::cout << ans << '\n';
	return 0;
}
