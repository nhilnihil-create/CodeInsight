#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

struct R{
    ll a, b;
    R(ll _a=1, ll _b=1){
        a = _a;
        b = _b;
    }
    bool operator>=(R x){
        return a*x.b >= x.a*b;
    }
};

ll digit_sum(ll n){
    ll ret = 0;
    while(n > 0){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

ll K;
vector<R> r;
vector<pair<ll, int>> v;
unordered_set<ll> st;
vector<ll> ans;

signed main(){
    cin >> K;
    for(ll i=1; i<=1000LL; i++){
        for(ll j=1; j<=1000000000000000LL; j*=10){
            ll tmp = i*j+j-1;
            if(tmp > 1e15L) continue;
            if(st.count(tmp)) continue;
            st.insert(tmp);
            v.pb({ tmp, r.size() });
            r.pb(R(tmp, digit_sum(tmp)));
        }
    }
    sort(all(v));
    reverse(all(v));
    
    R M = R((ll)1e18L, 1);
    rep(i, v.size()){
        if(M >= r[v[i].second]){
            M = r[v[i].second];
            ans.pb(v[i].first);
        }
    }
    sort(all(ans));
    rep(i, K) cout << ans[i] << endl;
}