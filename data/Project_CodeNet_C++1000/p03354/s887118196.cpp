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
    int DEBUG = 0;
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

    map<int, vector<int>> mp;
    rep(i,N) mp[uf.find(i)].push_back(p[i]);
    if (DEBUG) {
        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            cout << (itr->first);
            rep(i, (itr->second).size()) cout << " " << (itr->second)[i];
            cout << endl;
        }
    }

    ll ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        vector<int> val = itr->second;
        vector<int> cand;
        rep(i,val.size()) cand.push_back(p[val[i]]);
        if (DEBUG) {
            rep(i,cand.size()) cout << "c " << cand[i] << endl;
        }
        sort(val.begin(), val.end());
        sort(cand.begin(), cand.end());

        vector<int> result;
        set_intersection(begin(val), end(val),
                  begin(cand), end(cand),
                  inserter(result, end(result)));

        if (DEBUG) {
            cout << "result" << endl;
            rep(k, result.size()) {
                cout << " " << result[k];
            }
            cout << endl;
        }

        ans += result.size();
        if (DEBUG) cout << result.size() << endl;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
