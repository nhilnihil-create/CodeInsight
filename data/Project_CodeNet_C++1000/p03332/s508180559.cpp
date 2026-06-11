#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#ifndef LOCAL
#define endl '\n'
#endif

const int mod = 998244353;

int pwr(int a,int b) {
	int ans = 1;
	while(b) {
		if(b & 1) ans = (ans * 1LL * a) % mod;
		a = (a * 1LL * a) % mod;
		b >>= 1;
	}
	return ans;
}


const int N = 3e5 + 5;
ll fact[N], ifact[N];

ll go(int n, int a) {
	ll ans = (fact[n] * 1LL * ifact[a]) % mod;
	ans = (ans * 1LL * ifact[n - a]) % mod;
	return ans;
}

signed main() {
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fact[0] = 1;
	for(int i = 1; i < N; i++) {
		fact[i] = (i * 1LL * fact[i - 1]) % mod;
	}
	ifact[N - 1] = pwr(fact[N - 1], mod - 2);
	for(int i = N - 2; i >= 0; i--) {
		ifact[i] = (ifact[i + 1] * 1LL * (i + 1)) % mod;
	}
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	ll ans = 0;
	for(int i = 0; i <= n; i++) {
		ll j = (k - a * i);
		if(j >= 0 && j % b == 0 && j <= b * n) {
			j /= b;
			ans += (go(n, i) * 1LL * go(n, j)) % mod;
			ans %= mod;
		}
	}
	cout << ans;
	return 0;
}