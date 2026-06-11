#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

class UnionFind {
public:
    
    vl parent;  // 親ノード
    vl Siz;  // 集合の大きさ

    // コンストラクタ
    UnionFind(ll n): parent(n), Siz(n, 1) {
        rep(i, n) {
            parent[i] = i;
        }
    }

    // n要素で初期化
    void init(ll n) {
        parent.resize(n);
        Siz.assign(n, 1);
        rep(i, n) {
            parent[i] = i;
        }
    }

    // xの属する集合の根を求める
    ll root(ll x) {
        if(parent[x] == x) {
            return x;
        }
        else {
            return parent[x] = root(parent[x]);
        }
    }

    // xとyの属する集合を併合
    void unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if(x == y) {
            return;
        }
        if(Siz[x] < Siz[y]) {
            swap(x, y);
        }
        Siz[x] += Siz[y];
        parent[y] = x;
    }
    
    // xとyが同じ集合に属するかどうか
    bool same(ll x, ll y) {
        return root(x) == root(y);
    }

    // xの属する集合の要素数を求める
    ll size(ll x) {
        return Siz[root(x)];
    }
    
};

int main() {
    ll n, m;
    cin >> n >> m;

    vl p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }

    UnionFind Uni(n);
    Uni.init(n);

    rep(i, m) {
        ll x, y;
        cin >> x >> y;
        x--;  y--;
        Uni.unite(x, y);
    }

    ll ans = 0;
    rep(i, n) {
        if(Uni.same(p[i], i)) {
            ans++;
        }
    }
    
    out(ans);
    re0;
}