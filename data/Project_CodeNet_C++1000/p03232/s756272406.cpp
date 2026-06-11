#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1000000007LL;

// aのb乗を求める.
ll modpow(ll a, ll b) {
	if (a > mod) a %= mod;
	if (b == 0LL) return 1LL;
	ll tmp = modpow(a, b / 2);
	if (b & 1LL)
		return tmp * tmp % mod * a % mod;
	return tmp * tmp % mod;
}

// aの逆元を求める.
ll inverse(ll a) {
	return modpow(a, mod - 2);
}

int main() {
	int N; cin >> N;
	// Nの階乗を計算
	ll N_fact = 1;
	int nx = 2;
	while (nx <= N)
		N_fact = (N_fact * nx++) % mod;
	// 答えの計算
	ll res = 0;
	ll tmp = 0;
	for (int i = 1; i <= N; ++i)
		tmp = (tmp + inverse(i)) % mod;
	for (int i = 1; i <= N; ++i) {
		int a; cin >> a;
		res += a * N_fact % mod * tmp % mod;
		res %= mod;
		tmp += (inverse(i + 1LL) - inverse(N - (ll)i + 1LL) + mod) % mod;
		tmp %= mod;
	}
	cout << res << endl;
	return 0;
}