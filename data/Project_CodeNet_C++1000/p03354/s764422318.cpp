#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

class UnionFind {
    vector<int> rank;
    vector<int> p;
    void link(int rx, int ry) {
        if (rx == ry) return;
        if (rank[rx] > rank[ry]) p[ry] = rx;
        else p[rx] = ry;
        if (rank[rx] == rank[ry]) rank[ry]++;
    }
public:
    void makeSet(int x) {
        p[x] = x;
        rank[x] = 0;
    }
    UnionFind(int size) {
        rank.resize(size, 0);
        p.resize(size, 0);
        rep(i,size) makeSet(i);
    }
    int findSet(int x) {
        if (x != p[x]) p[x] = findSet(p[x]);
        return p[x];
    }
    bool same(int x, int y) {return findSet(x) == findSet(y);}
    void unite(int x, int y) {link(findSet(x), findSet(y));}
};

int main() {
    fast_io
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    UnionFind u(n);
    int x, y;
    rep(i,m) {
        cin >> x >> y;
        u.unite(x-1, y-1);
    }
    int ans = 0;
    rep(i,n) {
        if (u.same(i, p[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}