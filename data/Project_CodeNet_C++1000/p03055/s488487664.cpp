#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#include <cassert>


typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<llll> vllll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define eb  emplace_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair
#define clamp(v,lo,hi) min(max(v,lo),hi)

template <typename T>
inline bool found(set<T> &s, T elem) { return s.find(elem) != s.end(); }
template <typename T>
inline bool found(unordered_set<T> &s, T elem) { return s.find(elem) != s.end(); }
template <typename T, typename U>
inline bool found(map<T,U> &s, U elem) { return s.find(elem) != s.end(); }
template <typename T, typename U>
inline bool found(unordered_map<T,U> &s, U elem) { return s.find(elem) != s.end(); }
template <typename T>
inline bool found(vector<T> &s, T elem) { return find(s.begin(), s.end(), elem) != s.end(); }
inline int found(string &s, string t) { return (int)s.find(t); }
inline int found(string &s, int c) { return (int)s.find(c); }

template<typename T1, typename T2> inline void amin(T1 & a, T2 const & b) { if (a>b) a=b; }
template<typename T1, typename T2> inline void amax(T1 & a, T2 const & b) { if (a<b) a=b; }
template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

inline ll square(ll x) { return x * x; }
inline ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
template <typename T>
inline T mod(T a, T b) { return ((a % b) + b) % b; }

template <typename T>
int find_left(vector<T>& v, T elem) {
    return (int)(upper_bound(v.begin(), v.end(), elem) - v.begin()) - 1;
}
template <typename T>
int find_right(vector<T>& v, T elem) {
    return (int)(lower_bound(v.begin(), v.end(), elem) - v.begin());
}

const ll MOD=1000000007LL;

ll ADD(ll x, ll y) { return (x+y) % MOD; }
ll SUB(ll x, ll y) { return (x-y+MOD) % MOD; }
ll MUL(ll x, ll y) { return x*y % MOD; }
ll POW(ll x, ll e) { ll v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
ll DIV(ll x, ll y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

vvi nxt;
int diameter;

int sub(int u, int p=-1){
    vi ds;
    for (int v: nxt[u]){
        if (v==p) continue;
        int d = sub(v, u) + 1;
        ds.pb(d);
    }
    sort(ALL(ds));
    int L = ds.size();
    if (L == 0) {
        return 0;
    } else if (L == 1) {
        amax(diameter, ds[0]);
        return ds[0];
    } else {
        amax(diameter, ds[L-1] + ds[L-2]);
        return ds[L-1];
    }
}

bool solve(int N, vi& a, vi& b) {
    nxt.resize(N);
    rep(i,N-1){
        nxt[a[i]].pb(b[i]);
        nxt[b[i]].pb(a[i]);
    }
    diameter = 0;
    sub(0);

    vector<bool> dp(diameter+1, false);
    dp[0] = true;
    dp[1] = false;
    for(int i=2; i<=diameter; ++i) {
        if (dp[i-1]==false || dp[i-2]==false) dp[i] = true;
    }
    return dp[diameter];
}

int main() {
    int N; scanf("%d%*c", &N);
    vi a(N-1), b(N-1);
    rep(i,N-1) {
        scanf("%d %d%*c", &a[i], &b[i]);
        --a[i]; --b[i];
    }
    cout << (solve(N,a,b) ? "First":"Second") << endl;
    return 0;
}
