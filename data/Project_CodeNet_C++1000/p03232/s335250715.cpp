#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

const int MAX = 510000;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long FINV(int n){
    if (n < 0) return 0;
    return finv[n];
}

int main() {
    // 前処理
    COMinit();

    ll n;
    cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];

    ll ans = 0;

    ll sum[n+100] = {};
    sum[0] = 1;
    srep(i,1,n+10){
        sum[i] = sum[i-1];
        sum[i] += (ll)1 * inv[i+1] % MOD;
        sum[i] %= MOD;
    }

    rep(i,n){
        ll tmp = a[i] * fac[n] % MOD * (sum[i] + sum[n-1-i] + MOD - 1) % MOD;
        // cout << i << ' ' << tmp << endl;
        ans = (ans + tmp) % MOD;
    }

    /*
    rep(i,n){
        rep(j,n){
            tmp = fac[n] * finv[abs(j-i)+1] % MOD * fac[abs(j-i)] % MOD * a[i] % MOD;
            ans = (ans + tmp) % MOD;
        }
    }
    */
    
    cout << ans << endl;
    return 0;
}
