#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

string s;
ll N;

bool check(ll k){
    if (k>N)
        return false;
    ll r = k-1, l = N-k;

    if (l>=r)
        return true;

    rep(i,l,r){
        if (s[i]!=s[i+1])
            return false;
    }
    return true;
}

signed main() {
    cin>>s;
    N = s.size();

    ll ok=1, ng=1ll << 59;
    while(ok+1<ng){
        ll m = (ok+ng)/2;
        if (check(m)){
            ok = m;
        }else{
            ng = m;
        }
    }
    cout<<ok<<endl;

    return 0;
}
