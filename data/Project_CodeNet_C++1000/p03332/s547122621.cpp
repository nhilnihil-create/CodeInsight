#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int mod_pow(int n, int p, int m) {
    if (p == 0) return 1;
    if (p % 2 == 0) {
        int t = mod_pow(n, p / 2, m);
        return (t * t) % m;
    }
    return n * mod_pow(n, p - 1, m) % m;
}
int modinv(int a, int mod) {
    return mod_pow(a, mod - 2, mod);
}

const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
signed main() {
    COMinit();
    int n, a, b, k;
    int ans = 0;
    cin >> n >> a >> b >> k;
    rep(red, n + 1) {
        if (red * a > k || red * a + n * b < k) continue;
        if ((k - red * a) % b != 0) continue;
        int blue = (k - red * a) / b;
        //cout << red << " " << blue << endl;
        ans += COM(n, red) * COM(n, blue) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}