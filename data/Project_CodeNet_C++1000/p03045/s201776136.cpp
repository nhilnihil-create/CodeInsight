#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

struct UnionFind {
    vector<int> d;
    UnionFind(int n = 0): d(n, -1) {}
    int find(int x) {
        if(d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y);}
    int size(int x) { return -d[find(x)];}
    int count(int x) { return d[x];}
};

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        uf.unite(x, y);
    }
    int ans = 0;
    rep(i, n) {
        if(uf.count(i) < 0) ans++;
    }
    cout << ans << endl;
    return 0;
}
