#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;
const double PI=3.14159265358979323846;

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

int main() {
    long long N, M;
    cin >> N >> M;

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
        --(edges[i].first);
        --(edges[i].second);
    }

    UnionFind uf(N);

    vector<long long> ans(M);
    ans[M - 1] = N * (N - 1) / 2;
    for (int i = M - 1; i >= 1; i--) {
        const pair<int, int>& e = edges[i];
        if (uf.same(e.first, e.second)) {
            ans[i - 1] = ans[i];
        } else {
            ans[i - 1] = ans[i] - static_cast<long long>(uf.size(e.first)) * static_cast<long long>(uf.size(e.second));
        }
        uf.unite(e.first, e.second);
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
