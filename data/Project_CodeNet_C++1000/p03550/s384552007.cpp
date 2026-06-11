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
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for(ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
const ld EPS = 1e-12L;
const ld PI = 3.1415926535897932385L;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
template<typename T> void print(const T &x){ cout << x << endl; }
template<typename T> void print(const vector<T> &x){ rep(i, SZ(x)){ cout << x[i] << " \n"[i+1==SZ(x)]; } cout << flush; }
template<typename T> void print(const vector<T> &x, ll s, ll n){ repr(i, s, n){ cout << x[i] << " \n"[i+1==n]; } cout << flush; }
template<typename T> void printv(const vector<T> &x){ rep(i, SZ(x)){ cout << x[i] << "\n"; } cout << flush; }
template<typename T> void printv(const vector<T> &x, ll s, ll n){ repr(i, s, n){ cout << x[i] << "\n"; } cout << flush; }
template<typename T> void print(const vector<vector<T>> &x){ rep(i, SZ(x)){ rep(j, SZ(x[i])){ cout << x[i][j] << " \n"[j+1==SZ(x[i])]; } } cout << flush; }
template<typename T> void print(const vector<vector<T>> &x, ll s1, ll n1, ll s2, ll n2){ repr(i, s1, n1){ repr(j, s2, n2){ cout << x[i][j] << " \n"[j+1==n2]; } } cout << flush; }
template<typename T, size_t S> void print(const T (&x)[S], ll s = 0, ll n = S){ repr(i, s, n){ cout << x[i] << " \n"[i+1==n]; } cout << flush; }
template<typename T, size_t S> void printv(const T (&x)[S], ll s = 0, ll n = S){ repr(i, s, n){ cout << x[i] << "\n"; } cout << flush; }
template<typename T, size_t S1, size_t S2> void print(const T (&x)[S1][S2], ll s1 = 0, ll n1 = S1, ll s2 = 0, ll n2 = S2){ repr(i, s1, n1){ repr(j, s2, n2){ cout << x[i][j] << " \n"[j+1==n2]; } } cout << flush; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

const ll MAX = 2019;
ll n, z, w;
ll a[MAX];

ll g(ll xp, ll yp);

ll fmemo[MAX];
ll f(ll xp, ll yp){
    dump("f", xp, yp);
    ll xc = (xp == -1 ? z : a[xp]);
    ll yc = (yp == -1 ? w : a[yp]);
    if(fmemo[yp+1] != -1) return fmemo[yp+1];
    if(yp == n-1) return abs(xc-yc);
    ll ret = 0;
    repr(i, yp+1, n){
        chmax(ret, g(i, yp));
    }
    return fmemo[yp+1] = ret;
}

ll gmemo[MAX];
ll g(ll xp, ll yp){
    dump("g", xp, yp);
    ll xc = (xp == -1 ? z : a[xp]);
    ll yc = (yp == -1 ? w : a[yp]);
    if(gmemo[xp+1] != -1) return gmemo[xp+1];
    if(xp == n-1) return abs(xc-yc);
    ll ret = INF;
    repr(i, xp+1, n){
        chmin(ret, f(xp, i));
    }
    return gmemo[xp+1] = ret;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cin >> n >> z >> w;
    rep(i, n){
        cin >> a[i];
    }
    rep(i, MAX){
        fmemo[i] = -1;
        gmemo[i] = -1;
    }
    cout << f(-1, -1) << endl;
    return 0;
}