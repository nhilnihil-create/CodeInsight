#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

struct UnionFind {
    vector<int> d;
    // コンストラクタ　親は-頂点数を保管
    UnionFind(int N) : d(N, -1) {}

    int find(int x) {
        if (d[x] < 0) {
            return x;
        }
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (d[x] > d[y]) {
            swap(x, y);
        }
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--;

    UnionFind uf(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x, y);
    }

    vector<int> q(n);
    rep(i, n){
        q[p[i]] = i;
    }

    int ans = 0;
    rep(i, n){
        if(uf.same(i, q[i])) ans++;
    }
    cout << ans << endl;
}