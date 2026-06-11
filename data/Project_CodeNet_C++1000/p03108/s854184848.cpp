/**
*	created: 10.08.2020 17:04:33
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n,-1) {}
    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x,y);
        par[x] += par[y]; par[y] = x;
        return true;
    }
    bool same(int x, int y) {return root(x) == root(y);}
    int size(int x) {return -par[root(x)];}
};

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    reverse(all(a));
    reverse(all(b));
    UnionFind uf(n);
    int cnt = 0;
    vector<int> v;
    v.push_back(0);
    rep(i,m) {
        int x = a[i], y = b[i];
        if (uf.same(x,y)) v.push_back(cnt);
        else {
            cnt += uf.size(x) * uf.size(y);
            v.push_back(cnt);
            uf.unite(x,y);
        }
    }
    reverse(all(v));
    rep2(i,1,m+1) cout << n*(n-1)/2 - v[i] << endl;
    return 0;
}