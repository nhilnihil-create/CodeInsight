#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
const int MAX = 300001;
long long fac[MAX], finv[MAX], inv[MAX];

void comb_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long mod_comb(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    long long n, a, b, k;
    cin >> n >> a >> b >> k;
    comb_init();
    
    long long ans = 0;
    for (long long i = 0; i <= k / a; i++) {
        if ((k - a * i) % b == 0) {
            ans += mod_comb(n, i) * mod_comb(n, (k - a * i) / b) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}