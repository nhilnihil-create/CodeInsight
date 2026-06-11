#pragma region template
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
template<typename T> inline void print(const T &x){ cout << x << endl; }
template<typename T> inline void print(const vector<T> &x){ rep(i, SZ(x)){ cout << x[i] << " \n"[i+1==SZ(x)]; } cout << flush; }
template<typename T> inline void print(const vector<T> &x, ll s, ll n){ repr(i, s, n){ cout << x[i] << " \n"[i+1==n]; } cout << flush; }
template<typename T> inline void printv(const vector<T> &x){ rep(i, SZ(x)){ cout << x[i] << "\n"; } cout << flush; }
template<typename T> inline void printv(const vector<T> &x, ll s, ll n){ repr(i, s, n){ cout << x[i] << "\n"; } cout << flush; }
template<typename T> inline void print(const vector<vector<T>> &x){ rep(i, SZ(x)){ rep(j, SZ(x[i])){ cout << x[i][j] << " \n"[j+1==SZ(x[i])]; } } cout << flush; }
template<typename T> inline void print(const vector<vector<T>> &x, ll s1, ll n1, ll s2, ll n2){ repr(i, s1, n1){ repr(j, s2, n2){ cout << x[i][j] << " \n"[j+1==n2]; } } cout << flush; }
template<typename T, size_t S> inline void print(const T (&x)[S], ll s = 0, ll n = S){ repr(i, s, n){ cout << x[i] << " \n"[i+1==n]; } cout << flush; }
inline void print(const char* x){ cout << x << endl; }
template<typename T, size_t S> inline void printv(const T (&x)[S], ll s = 0, ll n = S){ repr(i, s, n){ cout << x[i] << "\n"; } cout << flush; }
template<typename T, size_t S1, size_t S2> inline void print(const T (&x)[S1][S2], ll s1 = 0, ll n1 = S1, ll s2 = 0, ll n2 = S2){ repr(i, s1, n1){ repr(j, s2, n2){ cout << x[i][j] << " \n"[j+1==n2]; } } cout << flush; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
#pragma endregion

const int M = 100010;
vvll g(M);
bool f[M];
ll d[M];

vector<int> visited(M, 0);

list<int> sorted_nodes;

void visit(int n){
    if(!visited[n]){
        visited[n] = 1;
        for(const auto& v: g[n]){
            visit(v);
        }
        sorted_nodes.emplace_front(n);
    }
}

void topologicalSort(ll start_, ll end_){
    for(int i = start_; i < end_; i++){
        visit(i);
    }
}
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n, m;
    cin >> n >> m;
    vll a(n-1+m), b(n-1+m);
    rep(i, n-1+m){
        cin >> a[i] >> b[i];
        g[a[i]].emplace_back(b[i]);
    }
    topologicalSort(1, n);
    vll nodes;
    for(auto&& e: sorted_nodes){
        nodes.emplace_back(e);
    }
    for(auto&& e: nodes){
        for(auto&& ee: g[e]){
            chmax(d[ee], d[e]+1);
        }
    }
    repr(i, 1, n+1){
        dump(i, d[i]);
    }
    vll par(n+1, 0);
    vector<bool> visited2(n+1, false);
    auto dfs = [&](auto& Self, int node) -> void{
        visited2[node] = true;
        for(auto&& e: g[node]){
            if(!visited2[e] && d[e] == d[node]+1){
                par[e] = node;
                Self(Self, e);
            }
        }
    };
    dfs(dfs, nodes[0]);
    repr(i, 1, n+1){
        print(par[i]);
    }
    return 0;
}
