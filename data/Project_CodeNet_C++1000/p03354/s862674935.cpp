#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// マクロ
// forループ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(ll)(b);i--)
// xにはvectorなどのコンテナ
#define ALL(x) (x)begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
// 出力
#define PRINT(x) cout<<(x)<<endl
#define PRINTA(x,n) REP(i,n)PRINT(x[i])
// 定数
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
// 略記
#define PB push_back
#define MP make_pair

const int MAX_N = 100000;
const int MAX_M = 100000;

int N, M, p[MAX_N], x[MAX_M], y[MAX_M];

struct UnionFind {
    vector<int> par;

    UnionFind(int N) : par(N) {
        REP(i, N) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
        return;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    cin >> N >> M;
    REP(i, N) {
        cin >> p[i];
        p[i]--;
    }
    REP(i, M) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    UnionFind tree(N);

    REP(i, M) tree.unite(x[i], y[i]);

    int ans = 0;
    REP(i, N) {
        if (tree.same(p[i], i)) ans++;
    }
    PRINT(ans);
    return 0;
}