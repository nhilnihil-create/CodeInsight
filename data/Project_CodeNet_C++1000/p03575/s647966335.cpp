#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        REP(i, N) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, M; cin >> N >> M;
    vector<int> a(M), b(M);
    REP(i, M) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    
    int ans = 0;
    REP(i, M) {
        UnionFind tree(N);
        REP(j, M) {
            if (i == j) continue;
            tree.unite(a[j], b[j]);
        }
        bool is_bridge = false;
        REP(j, N) {
            if (!(tree.same(0, j))) is_bridge = true;
        }
        if (is_bridge) ans++;
    }
    PRINT(ans);
    return 0;
}