#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 998244353;


const int MAX = 510000;
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

ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}


int main(){
    ll n, a, b, k, ans = 0;
    cin >> n >> a >> b >> k;
    COMinit();
    for(ll i = 0; i <= n; i++){
        if ((k - a*i) % b != 0 || k < a*i) continue;
        ll j = (k - a*i) / b;
        ans += (COM(n, i) * COM(n, j)) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
