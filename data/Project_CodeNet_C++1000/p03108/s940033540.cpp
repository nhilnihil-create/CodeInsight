#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n,-1) {}

    int find(int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    vi a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    UnionFind uf(n);
    vll ans(m+1);
    ans[m] = n * (n-1) / 2;
    for (int i = m-1; i >= 0; i--) {
        if (uf.same(a[i], b[i])) {
            ans[i] = ans[i+1];
        } else {
            int x = uf.size(a[i]), y = uf.size(b[i]);
            ans[i] = ans[i+1] - x * y;
        }
        uf.unite(a[i], b[i]); 
    }
    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << endl;
    }
}