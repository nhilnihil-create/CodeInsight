#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mod 1000000007

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
#define MAX_FACT 100001
ll fact[MAX_FACT];

int main() {
    int N;
    cin >> N;
    vector<ll>A(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // 階乗計算
    fact[0]=1;
    for(int i = 1; i < MAX_FACT; ++i) {
        fact[i] = fact[i-1] * i % mod;
    }
    
    // 1/i の累積和
    vector<ll>cuSum(N+1, 0);
    for (int i = 1; i <= N; ++i) {
        cuSum[i] = (cuSum[i-1] + Inverse(i)) % mod;
    }

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += A[i] * (cuSum[i] + cuSum[N-i+1] + mod - 1);
        ans %= mod;
    }
    ans = ans * fact[N] % mod;
    cout << ans;
    return 0;
}