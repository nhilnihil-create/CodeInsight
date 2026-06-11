#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

struct Combination {
	vector<int64_t> _fact, _rfact, _inv;
	int64_t MOD;

	Combination(size_t sz, int64_t mod) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1), MOD(mod) {
		_fact[0] = _rfact[sz] = _inv[0] = 1;
		for (int i = 1; i <= sz; ++i) {
			_fact[i] = _fact[i - 1] * i % MOD;
		}
		_rfact[sz] = inverse(_fact[sz]);
		for (int i = sz - 1; i >= 0; --i) {
			_rfact[i] = _rfact[i + 1] * (i + 1) % MOD;
		}
		for (int i = 1; i <= sz; ++i) {
			_inv[i] = _rfact[i] * _fact[i - 1] % MOD;
		}
	}

	inline int64_t fact(int k) const { return _fact[k]; }
	inline int64_t rfact(int k) const { return _rfact[k]; }
	inline int64_t inv(int k) const { return _inv[k]; }

	int64_t inverse(int64_t x) const { return pow(x, MOD - 2); }
	int64_t pow(int64_t x, int64_t n) const {
		int64_t ret = 1;
		while (n > 0) {
			if (n & 1) { (ret *= x) %= MOD; }
			(x *= x) %= MOD;
			n >>= 1;
		}
		return ret;
	}

	int64_t P(int n, int r) const {
		if (r < 0 || n < r) { return 0; }
		return fact(n) * rfact(n - r) % MOD;
	}
	int64_t C(int n, int r) const {
		if (r < 0 || n < r) { return 0; }
		return fact(n) * rfact(r) % MOD * rfact(n - r) % MOD;
	}
	int64_t H(int n, int r) const {
		if (n < 0 || r < 0) { return 0; }
		return r == 0 ? 1 : C(n + r - 1, r);
	}
};

int main() {
	constexpr Int MOD = 998244353;
	Int N, A, B, K;
	cin >> N >> A >> B >> K;

	Combination cb(N, MOD);
	Int ans = 0;
	for (Int x = 0; x <= N; ++x) {
		if ((K - A * x) % B != 0) { continue; }
		(ans += (cb.C(N, x) * cb.C(N, (K - A * x) / B)) % MOD) %= MOD;
	}
	cout << ans % MOD << endl;

	return 0;
}
