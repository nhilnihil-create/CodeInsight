#include <bits/stdc++.h>
#include <stdio.h>

#define INF 1e18
#define REP(i, n) for (int i=0; i<n; i++)
#define print(x) cout << x << endl
#define debug(x) cout << #x << " = "<< x << endl

const double PI=3.141592653589793238462643383279502884197169399375105820974944;

typedef long long ll;

using namespace std;

struct UnionFind {
    vector<int> parrent;
    
    UnionFind(int N) : parrent(N) {
        REP(i, N) parrent[i] = i;
    }

    int root(int x) {
        if (parrent[x] == x) return x;
        return parrent[x] = root(parrent[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        parrent[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N), to(N);
    REP(i, N) cin >> P[i];

    UnionFind tree(N);

    REP(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        tree.unite(x, y);
    }

    int ans = 0;
    REP(i, N) {
        if (tree.same(i, P[i]-1)) ans++;
    }
    print(ans);
}

signed main() {
    solve();
}
