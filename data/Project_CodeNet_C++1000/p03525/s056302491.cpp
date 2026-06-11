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

void pr(ll n){
    cout << n << endl;
    exit(0);
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vll d(n);
    rep(i, n){
        cin >> d[i];
    }
    d.emplace_back(0);
    n++;
    sort(ALL(d));
    vll cnt(13, 0);
    rep(i, n){
        cnt[d[i]]++;
    }
    if(cnt[0] >= 2) pr(0);
    if(cnt[12] >= 2) pr(0);
    repr(i, 1, 12){
        if(cnt[i] >= 3) pr(0);
    }
    vll prob;
    ll c = 0;
    rep(i, n){
        if(d[i] > 0 && d[i] < 12 && cnt[d[i]] == 1){
            c++;
            prob.emplace_back(d[i]);
        }
    }
    rep(i, n){
        if(d[i] == 0 || d[i] == 12){
            prob.emplace_back(d[i]);
        }
    }
    repr(i, 1, 12){
        if(cnt[i] == 2){
            prob.emplace_back(i);
            prob.emplace_back(24-i);
        }
    }
    ll m = 1ll << c;
    ll ans = 0;
    rep(i, m){
        vll e{prob};
        rep(j, c){
            if((i >> j) & 1){
                e[j] = 24 - e[j];
            }
        }
        dump(e);
        sort(ALL(e));
        ll tmp = INF;
        rep(i, n-1){
            chmin(tmp, e[i+1]-e[i]);
        }
        chmin(tmp, e[0]-e[n-1]+24);
        chmax(ans, tmp);
    }
    pr(ans);
    return 0;
}