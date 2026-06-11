#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const long long MAX = 10000000;
const long long MOD = 998244353;


long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        //そのまま計算すると負の値になるのでMODを足す
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(long long n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    // 前処理
    COMinit();
    long long ans = 0;
    long long n1, a, b, k, x, y;
    cin >> n1 >> a >> b >> k;

    for(x=0;x<=n1;x++) {
        y = (k - a*x) / b;
        if((k - a*x) % b == 0 && y <= n1 && y>=0) {
            //cout << x << " " << y << endl;
            ans = (ans + (COM(n1, x) * COM(n1, y))%MOD)%MOD; 
        }
    }
    cout << ans << endl;
}