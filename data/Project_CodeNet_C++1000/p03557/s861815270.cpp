#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <functional>
#include <limits>
#include <map>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(ll i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(ll i = 0; i <=(ll)(n); i++)

ll pow(ll a, ll n) { //compute a^n with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll pow(ll a, ll n, ll mod) { //compute a^n (mod mod) with o(logn)
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int MAX = 199;
const int MOD = 1000000007;
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

//順列計算
ll PER(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[n - k] % MOD) % MOD;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    rep0(i, n-1) cin >> a[i];
    rep0(i, n-1) cin >> b[i];
    rep0(i, n-1) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll sum_b[n+1];
    sum_b[0] = 0;
    rep0(i, n-1){
        int idx = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        sum_b[i+1] = sum_b[i] + idx;
    }

    ll cnt = 0;
    rep0(i, n-1){
        auto idx = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
        cnt += sum_b[idx];
    }

    cout << cnt << endl;
    return 0;
}