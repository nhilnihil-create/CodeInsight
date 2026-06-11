#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MAX = 300005;
const int MOD = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    // 前処理
    COMinit();
    // 計算例
    int n,a,b;
    ll k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    rep(i,n+1){
      if((k-a*i)%b==0&&(k-a*i)/b<=n){
        //cout << i << (k-a*i)/b << endl;
        ans += COM(n,i) * COM(n,(k-a*i)/b);
        ans %= 998244353;
      }
    }
    cout << ans << endl;
}
