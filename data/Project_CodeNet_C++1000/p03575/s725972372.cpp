#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
struct UnionFind {
    vector<int> par, rank;

    UnionFind(int N) : par(N), rank(N) {
        rep(i, N) par[i] = i, rank[i] = 0;
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
        }
        else {
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

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);

    rep(i, M) cin >> a[i] >> b[i];

    int ans = 0;
    rep(i, M) {
        UnionFind tree(N);
        rep(j, M) {
            if (i == j) continue;
            tree.unite(a[j] - 1, b[j] - 1);
        }
        int root = tree.root(0);
        repd(i, 1, N) {
            if (root != tree.root(i)) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}