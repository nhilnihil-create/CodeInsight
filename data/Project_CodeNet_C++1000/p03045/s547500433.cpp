/**
*	created: 01.09.2020 14:13:56
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

// UnionFind
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n,-1) {}
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x,y);
        par[x] += par[y]; par[y] = x;
        return true;
    }
    bool issame(int x, int y) {return root(x) == root(y);}
    int size(int x) {return -par[root(x)];}
};

signed main() {
    int n, m; cin >> n >> m;
    UnionFind uf(n);
    vector<int> a(m), b(m);
    int c;
    rep(i,m) {
        cin >> a[i] >> b[i] >> c;
        a[i]--; b[i]--;
        uf.merge(a[i],b[i]);
    }
    set<int> v;
    rep(i,n) v.insert(uf.root(i));
    cout << v.size() << endl;
    return 0;
}