#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

class UnionFindTree {
   public:
    vector<int> parent;
    vector<int> siz;

    UnionFindTree(int n) {
        siz.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void unite(int x, int y) {
        int rx = root(x); int ry = root(y);
        if (rx == ry) return;
        if (siz[rx] < siz[ry]) swap(rx, ry);
        siz[rx] += siz[ry];
        parent[ry] = rx;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<int> P(N), idx(N);
    REP(i, 0, N) {
        int p; cin >> p; p--;
        P[i] = p;
        idx[p] = i;
    }

    UnionFindTree uft(N);
    REP(i, 0, M) {
        int a, b; cin >> a >> b;
        uft.unite(--a, --b);
    }

    int ans = 0;
    REP(i, 0, N) {
        if (P[i] == i || uft.same(i, idx[i])) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}