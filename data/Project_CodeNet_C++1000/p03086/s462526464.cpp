#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
#define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;


map<ll, ll> prime_factors(ll n) {
    map<ll, ll> res;
    if(n == 1) { // n=1 の素因数分解は n^1
        res[n] = 1;
        return res;
    }
    for(ll i = 2, _n = n; i*i <= _n; ++i) {
        while(n % i == 0) {
            ++res[i]; // 素数i^{res[i]}
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}
signed main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    int tmp = 0;
    rep(i,n) { 
       if(s[i]=='A' ||s[i]=='C' ||s[i]=='G' ||s[i]=='T') {
            tmp++;
        }else {
            tmp = 0;
        }
        ans = max(tmp,ans);
    }
    cout << ans << endl;
    return 0;
}

