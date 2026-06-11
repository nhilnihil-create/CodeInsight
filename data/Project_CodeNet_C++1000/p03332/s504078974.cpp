#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

constexpr Int mod = 998244353;
vector<Int> fact, ifact, comb;
Int inv(Int n){
    Int p = mod - 2;
    Int t = n;
    Int res = 1;
    for(;p>0; p>>=1){
        if(p & 1) res = res * t % mod;
        t = t * t % mod;
    }
    return res;
}

int main(){
    Int n, a, b, k; cin >> n >> a >> b >> k;
    fact.resize(n+1);
    fact[0] = 1;
    for(Int i=1; i<=n; ++i) fact[i] = i * fact[i-1] % mod;
    ifact.resize(n+1);
    for(Int i=1; i<=n; ++i) ifact[i] = inv(fact[i]);
//    for(Int i=1; i<=n; ++i) cout << i << " " << ifact[i] << "\n";
    comb.resize(n+1);
    comb[0] = 1;
    for(Int i=1; i<=n-1; ++i) comb[i] = fact[n] * ifact[i] % mod * ifact[n-i] % mod;
//    for(Int i=1; i<=n-1; ++i) cout << i << " " << comb[i] << "\n";
    comb[n] = 1;
    Int ans = 0;
    for(Int i=0; i<=n; ++i){
        if(k - i*a >= 0 && (k - i*a) % b == 0){
            Int j = (k - i*a) / b;
            if(j > n) continue;
            ans = (ans + comb[i] * comb[j] % mod) % mod;
//            cout << i << " " << j << " " << ans << "\n";
        }
    }
    cout << ans << "\n";
//    cout << inv(1) << " " << inv(2) << " " << inv(998244352) << "\n";
}