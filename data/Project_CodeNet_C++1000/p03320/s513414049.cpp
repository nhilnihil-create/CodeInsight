#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (b)-1; i >= (a); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(ull x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

ll digsum(ll n){
    ll ret = 0;
    while(n){
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    VV<ld> a;
    repr(i, 1, 10){
        a.emplace_back(V<ld>{(ld)i/digsum(i), (ld)i, (ld)digsum(i)});
    }
    repr(i, 1, 10){
        ll j = 10 * i + 9;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 1, 10){
        ll j = 100 * i + 99;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 100 * i + 99;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 1000 * i + 999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 10000 * i + 9999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 100000 * i + 99999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 1000000 * i + 999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 10000000 * i + 9999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 100000000 * i + 99999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 1000000000 * i + 999999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 10, 100){
        ll j = 10000000000 * i + 9999999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 100, 1000){
        ll j = 10000000000 * i + 9999999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 100, 1000){
        ll j = 100000000000 * i + 99999999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    repr(i, 100, 1000){
        ll j = 1000000000000 * i + 999999999999;
        a.emplace_back(V<ld>{(ld)j/digsum(j), (ld)j, (ld)digsum(j)});
    }
    stable_sort(ALL(a));
    ll ma = 0;
    ll K;
    cin >> K;
    ll cnt = 0;
    rep(i, SZ(a)){
        if(chmax(ma, (ll)a[i][1])){
            cout << (ll)a[i][1] << "\n";
            cnt++;
        }
        if(cnt == K) break;
    }
    return 0;
}