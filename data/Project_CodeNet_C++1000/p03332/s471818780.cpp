#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 300005;
const ll INF = 1001001001;
const ll MOD = 998244353;

ll N, A, B, K, ans=0, tmp=0;
ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

signed main(){
    COMinit();
    cin >> N >> A >> B >> K;
    for(int i=0;i<=N;i++) {
        tmp = K-A*i;
        if(tmp%B!=0) continue;
        tmp /= B;
        if(tmp>N) continue;
        ans += COM(N,i)*COM(N,tmp);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}