#include <bits/stdc++.h>
#include <numeric>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;

const int MAX = 510000;
const int MOD = 998244353;

ll fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    rep(i, 2, MAX){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    COMinit();

    ll N, A, B, K;
    cin >> N >> A >> B >> K;

    ll res = 0LL;
    for (ll a = 0LL; a <= N; ++a) {
        // a*A + b*B == K
        ll bB = K - a*A;
        if (bB % B != 0) continue;

        // a + b <= N
        ll b = bB / B;
        //if (b > N) continue;
        
        res += COM(N, a) * COM(N, b) % MOD;
        res %= MOD;
    }

    cout << res << endl;
}