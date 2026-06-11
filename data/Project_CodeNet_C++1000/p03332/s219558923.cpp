#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;

ll N, A, B, K;
const ll mod = 998244353;


// mod演算ライブラリ (modは素数限定)
// mod = 1000000007

ll add_mod(ll a, ll b) {  // a + b
	return (a + b) % mod;
}

ll sub_mod(ll a, ll b) {  // a - b
	return (a + mod - b) % mod;
}

ll mul_mod(ll a, ll b) {  // a * b
	return ((a % mod) * (b % mod)) % mod;
}

ll pow_mod(ll x, ll y) { // x^y 単品利用可
	if (y == 0) return 1;
	else if (y == 1) return x % mod;
	else if (y % 2 == 0) {
		ll tmp = pow_mod(x, y / 2) % mod;
		return tmp * tmp % mod;
	}
	else {
		ll tmp = pow_mod(x, y / 2) % mod;
		return ((tmp * tmp) % mod) * x % mod;
	}
}

ll dvs_mod(ll a, ll b) { // a / b (?)
	return mul_mod(a, pow_mod(b, mod - 2));
}

const ll SIZE_mod = 300005;
ll invfact[SIZE_mod];
ll fact[SIZE_mod];

void factset(int a) {  // a までの 階乗 % mod 表を作成
	fact[0] = 1;
	for (int i = 1; i <= a; ++i) {
		fact[i] = mul_mod(fact[i - 1], i);
	}
}

void cmbset(int a) {  // 1~a までの階乗と階乗数の逆元のmod(mod)を用意 O(a)
	factset(a);
	invfact[a] = pow_mod(fact[a], mod - 2);
	invfact[0] = 1;
	for (int i = a - 1; i >= 1; --i) {
		invfact[i] = mul_mod(invfact[i + 1], i + 1);
	}
}

ll cmb_mod(int n, int r) {  // nCr % mod  (cmbset後に使用)
	if (n < r || r < 0 || n < 0) return 0;
	return mul_mod(fact[n], mul_mod(invfact[r], invfact[n - r]));
}

ll prm_mod(int n, int r) {  // nPr % mod
	return mul_mod(cmb_mod(n, r), fact[n]);
}

ll homo_mod(int n, int r) {  // nHr % mod
	return cmb_mod(n + r - 1, r);
}


int main() {

	cin >> N >> A >> B >> K;
	cmbset(N + 1);

	ll ans = 0;
	for (ll p = 0; p <= K / A; ++p) {
		if ((K - p * A) % B == 0) {
			ll q = (K - p * A) / B;

			ans = add_mod(mul_mod(cmb_mod(N, p), cmb_mod(N, q)), ans);
		}
	}

	cout << ans << endl;
}