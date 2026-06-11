#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0): d(n, -1) {}
    int find(int x) {
        if (d[x]<0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x==y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size(int x) {
        return -d[find(x)];
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    UnionFind u(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        u.unite(x, y);
    }
    int ans = 0;
    rep(i, n) {
        if (u.same(i, p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}
