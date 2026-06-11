#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mod 998244353

// F_mod 上でのべき乗, 蟻本p115
ll modPow(ll x, ll n) {
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

// Fermat の小定理を用いた F_mod 上での逆元計算x^(mod-2)
ll Inverse(ll x){
    return modPow(x, mod - 2);
}

// iの階乗 = fact[i], main内の階乗計算をする必要がある
#define MAX_FACT 300001
ll fact[MAX_FACT];

ll nCk(int n, int k){
    //　n_C_kの計算, 蟻本p.263
    ll ans = fact[n] * Inverse(fact[k] * fact[n-k] % mod);
    ans %= mod;
    return ans;
}

int main() {
    ll N, A, B, K;
    cin >> N >> A >> B >> K;

    // 階乗計算
    fact[0]=1;
    for(int i = 1; i < MAX_FACT; ++i) {
        fact[i] = fact[i-1] * i % mod;
    }

    ll ans = 0;
    // A点加点するブロックの数
    for (int i = 0; i <= N; ++i) {
        ll rem = K - A * i;
        if(rem < 0) break;
        if(rem % B != 0 || rem / B > N) continue;
        ll k = rem / B;
        ans += nCk(N, i) * nCk(N, k);
        ans %= mod;
    }
    cout << ans;
    return 0;
}