#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

const int MAX = 510000;
const int MOD = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM (int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    COMinit();

    ll N, A, B, K;
    cin >> N >> A >> B >> K;

    ll ans = 0;
    for (ll i = 0; i <= N; i++) {
        if ((K-A*i)%B == 0) {
            ll j = (K-A*i)/B;
            ans += COM(N, i) * COM(N, j) % MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;
}