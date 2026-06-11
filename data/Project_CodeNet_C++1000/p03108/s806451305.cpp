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
    vector<ll> par, rank, cnt;

    UnionFind(ll N) : par(N), rank(N), cnt(N) {
        rep(i, N) par[i] = i, rank[i] = 0, cnt[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        int cntx = cnt[rx], cnty = cnt[ry];
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            par[rx] = ry;
        }
        else {
            par[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
        cnt[rx] += cnty; cnt[ry] += cntx;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    ll getCnt(int x) {
        return cnt[root(x)];
    }
};

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(M), B(M);
    UnionFind tree(N);

    ll ans = N * (N - 1);
    ans /= 2;

    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    vector<ll> res(M);
    res[M - 1] = ans;

    for (ll i = M - 1; i >= 1; i--) {
        if (tree.same(A[i], B[i])) {
            res[i - 1] = res[i];
            continue;
        }
        ll size_b1 = tree.getCnt(A[i]);
        ll size_b2 = tree.getCnt(B[i]);
        // cout << i << " " << size_b1 << " " << size_b2 << endl;
        tree.unite(A[i], B[i]);
        ll size_a = tree.getCnt(A[i]);
        size_b1 = (size_b1 * (size_b1 - 1)) / 2;
        size_b2 = (size_b2 * (size_b2 - 1)) / 2;
        size_a = (size_a * (size_a - 1)) / 2;
        ans -= size_a - size_b1 - size_b2;
        res[i - 1] = max(0LL, ans);
    }

    rep(i, M) cout << res[i] << endl;
    return 0;
}
