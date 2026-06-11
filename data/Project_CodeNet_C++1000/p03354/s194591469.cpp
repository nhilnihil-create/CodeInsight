#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;
const int MAX = 1000000010;
const ll MOD = 1000000007;

struct UnionFind {
    vector<int> par; vector<int> rank;

    UnionFind(int N) : par(N), rank(N) {
        for (int i = 0; i < N; i++) {
            par[i] = i; 
            rank[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;
        } else {
            par[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M; cin >> N >> M;
    UnionFind T(N + 1);
    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) cin >> p[i];

    for (int i = 0; i < M; i++) {
        int x, y; cin >> x >> y;
        T.unite(p[x], p[y]);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (T.same(p[i], i)) cnt++;
    }

    cout << cnt << endl;
    return 0;
}