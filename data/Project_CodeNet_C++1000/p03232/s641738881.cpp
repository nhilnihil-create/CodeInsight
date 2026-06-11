#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

// mod付きコンビネーション
const int MAX = 1100000;
const int MOD = 1000000007;

Int fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
Int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    Int n;
    cin >> n;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    COMinit();
    vector<Int> b(n + 1, 0);
    for (Int i = 1; i <= n; i++) {
        b[i] = inv[i];
    }
    for (Int i = 0; i < n; i++) {
        b[i + 1] += b[i];
        b[i + 1] %= mod;
    }
    Int res = 0;
    for (Int i = 0; i < n; i++) {
        res += a[i] * (b[i + 1] + b[n - i] - 1) % mod;
        res %= mod;
    }
    dump(res * fac[n] % mod);
    return 0;
}