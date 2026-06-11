#include<iostream>

using namespace std;

typedef long long ll;

namespace comb {
	ll fact[500001];
	ll fact_inv[500001];
	const ll MOD = 998244353;

	ll modpow(ll a, ll b) {
		ll base = 1, kakeru = a;
		while (b > 0) {
			if (b & 1)base *= kakeru, base %= MOD;
			kakeru *= kakeru, kakeru %= MOD;
			b >>= 1;
		}
		return base;
	}

	void setup() {
		fact[0] = 1, fact[1] = 1;
		for (int i = 2; i <= 500000; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
		}

		fact_inv[500000] = modpow(fact[500000], MOD - 2);

		for (int i = 499999; i >= 0; i--) {
			fact_inv[i] = fact_inv[i + 1] * (i + 1);
			fact_inv[i] %= MOD;
		}

	}

	ll combination(int a, int b) {
		if (a - b < 0)return 0;
		ll ret = fact[a];
		ret *= fact_inv[b], ret %= MOD;
		ret *= fact_inv[a - b], ret %= MOD;
		return ret;
	}

	ll permutation(int a, int b) {
		if (a - b < 0)return 0;
		ll ret = fact[a];
		ret *= fact_inv[a - b], ret %= MOD;
		return ret;
	}

	ll homogeneous(int a, int b) {
		return combination(a + b - 1, b);
	}

}

ll N, A, B, K;

int main() {
	comb::setup();

	cin >> N >> A >> B >> K;
	
	ll ans = 0;
	for (ll i = 0; i <= N && i * A <= K; i++) {
		if ((K - i * A) % B == 0) {
			ll j = (K - i * A) / B;
			if (j > N)continue;
			ans += ((comb::combination(N, i) * comb::combination(N, j))) % comb::MOD;
		}
		ans %= comb::MOD;
	}
	cout << ans << endl;
	return 0;
}