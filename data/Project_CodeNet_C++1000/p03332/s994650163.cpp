#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int mod = 998244353;
const int IMAX = 600300;
constexpr ll modpow(ll A, ll B) {
	ll kotae = 1;
	while (B > 0) {
		if (B & 1) kotae = kotae * A % mod;
		A = A * A % mod;
		B >>= 1;
	}
	return kotae;
}
class unko {
public:
	int fac[IMAX + 1], ifac[IMAX + 1], inv[IMAX + 1];
	constexpr unko() : fac(), ifac(), inv() {
		fac[0] = 1;
		rep1(i, IMAX) fac[i] = ll(fac[i - 1]) * i % mod;
		ifac[IMAX] = modpow(fac[IMAX], mod - 2);
		for (int i = IMAX; i > 0; i--) ifac[i - 1] = ll(ifac[i]) * i % mod;
		inv[0] = 1;
		rep1(i, IMAX) inv[i] = ll(ifac[i]) * fac[i - 1] % mod;
	}
	int comb(int A, int B) {
		return ll(fac[A]) * ifac[B] % mod * ifac[A - B] % mod;
	}
} f;

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	ll N, A, B, K;
	scanf("%lld %lld %lld %lld", &N, &A, &B, &K);

	if (K == 0) {
		printf("1\n");
		return 0;
	}

	ll GCD = __gcd(A, B);
	if (K % GCD) {
		printf("0\n");
		return 0;
	}

	A /= GCD;
	B /= GCD;
	K /= GCD;

	if (A < B) swap(A, B);

	if (A == 1) {
		ll k = min(K, 2 * N - K);
		if (k < 0) {
			printf("0\n");
			return 0;
		}
		ll kari = 1ll * f.fac[2 * N] % mod * f.ifac[k] % mod * f.ifac[2 * N - k] % mod;
		printf("%lld\n", kari);
		return 0;
	}

	ll hajime = max(0ll, (K - N * B + A - 1) / A);
	ll owari = min(N, K / A);
	const int b = B;
	ll kotae = 0;
	K -= hajime * A;
	if (b != 1) {
		for (int i = hajime; i <= owari; i++) {
			if (K % b == 0) {
				int j = K / b;
				while (i <= owari) {
					kotae += ll(f.ifac[N - i]) * f.ifac[i] % mod * f.ifac[N - j] % mod * f.ifac[j] % mod;
					i += B;
					j -= A;
				}
			}
			K -= A;
		}
	}
	else {
		for (int i = hajime; i <= owari; i++) {
			kotae += ll(f.ifac[N - i]) * f.ifac[i] % mod * f.ifac[N - K] % mod * f.ifac[K] % mod;
			K -= A;
		}
	}

	kotae %= mod;
	kotae *= f.fac[N];
	kotae %= mod;
	kotae *= f.fac[N];
	kotae %= mod;

	printf("%lld\n", kotae);

	Would you please return 0;
}