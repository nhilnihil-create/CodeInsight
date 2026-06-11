#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

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
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> p(N);
    rep(i, N) {
        cin >> p[i];
        p[i]--;
    }
    UnionFind uf = UnionFind(N);
    rep(i,M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x,y);
    }

    map<int, set<int>> mp;
    rep(i,N) mp[uf.find(i)].insert(p[i]);

    ll ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        set<int> val = itr->second;
        set<int> cand;
        for (auto it = val.begin(); it != val.end(); it++) {
            cand.insert(p[*it]);
        }

        vector<int> result;
        set_intersection(begin(val), end(val),
                  begin(cand), end(cand),
                  inserter(result, end(result)));

        ans += result.size();
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
