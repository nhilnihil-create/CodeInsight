#include <bits/stdc++.h>
using namespace std;
#define all(V) V.begin(),V.end()
using ll = long long;
const ll MOD = 1000000007;

ll fact[100010], inv[100010], fr[100010];
ll N;

ll modpow(ll x, ll y) {
	ll ans = 1;
	while (y) {
		if (y & 1)ans *= x;
		x *= x;
		ans %= MOD;
		x %= MOD;
		y /= 2;
	}
	return ans;
}

ll ncr(ll r) {
	return fact[N] * inv[N - r] % MOD * inv[r] % MOD;
}

ll f(ll x) {
	ll per = fact[N - x] * fact[x - 1] % MOD;
	ll com = ncr(x);
	return per * com % MOD;
}

int main() {
	fact[0] = 1, inv[0] = 1;
	for (ll i = 1;i < 100010;i++)fact[i] = fact[i - 1] * i % MOD, inv[i] = modpow(fact[i], MOD - 2);
	cin >> N;
	vector<ll> A(N), B(N);
	for (int i = 0;i < N;i++)cin >> A[i];

	for (int i = 1;i <= N;i++) {
		fr[i] = (f(i) + fr[i - 1]) % MOD;
	}

	for (int i = 0;i < N;i++) {
		B[i] = fr[i + 1] + fr[N - i] - fr[1];
		B[i] %= MOD;if (B[i] < 0)B[i] += MOD;
	}
	ll ans = 0;
	for (int i = 0;i < N;i++) {
		ans += A[i] * B[i];
		ans %= MOD;
	}
	cout << ans << endl;
}