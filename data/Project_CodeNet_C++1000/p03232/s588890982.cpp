#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;
int A[100000];
ll fact[100001];
ll sum[100001];
ll mod_pow(ll a, ll b) {
	if (b == 0) return 1;
	if (b % 2 == 0) {
		ll x = mod_pow(a, b / 2);
		return (x*x) % MOD;
	}
	return (a*mod_pow(a, b - 1)) % MOD;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
		sum[i] = (sum[i - 1] + mod_pow(i, MOD - 2)) % MOD;
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ll add = sum[i + 1] + sum[N - i];
		(add += MOD - 1) %= MOD;
		(add *= fact[N]) %= MOD;
		(add *= A[i]) %= MOD;
		(ans += add) %= MOD;
	}
	cout << ans << endl;
}