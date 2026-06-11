#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

struct UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<ll> size;

    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n);
        rep(i, n) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int root(int x) {
        if (parent[x] == x) return x;
        parent[x] = root(parent[x]);
        return parent[x];
    }

    bool isSame(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        if (isSame(x, y)) return;
        x = root(x); y = root(y);
        if (rank[x] > rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        parent[y] = x;
        size[x] += size[y];
    }

    ll get_size(int x) {
        if (root(x) == x) return size[x];
        size[x] = get_size(root(x));
        return size[x];
    }
};

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(M), B(M);
    for (ll i = M-1; i >= 0; i--) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }
    vector<ll> ans(M);
    ans[M-1] = N*(N-1)/2;
    UnionFind UF = UnionFind(N);
    rep(i, M-1) {
        if (UF.isSame(A[i], B[i])) {
            ans[M-i-2] = ans[M-i-1];
            continue;
        }
        ans[M-i-2] = ans[M-i-1] - UF.get_size(A[i])*UF.get_size(B[i]);
        UF.unite(A[i], B[i]);
    }
    rep(i, M) cout << ans[i] << endl;
}
