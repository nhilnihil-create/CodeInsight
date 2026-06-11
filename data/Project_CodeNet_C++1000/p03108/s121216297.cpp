#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct PartiallyPersistentUnionFindTree {
    vector<int> par, time; vector<vector<pair<int, int>>> sz; int now;
    int operator[](int x) const { return find(x); }
    void build(int n) { par.assign(n, 1); time.assign(n, INT32_MAX); sz.assign(n, { { 0, 1 } }); now = 0; }
    int find(int t, int x) const { while (time[x] <= t) x = par[x]; return x; }
    int find(int x) const { return find(now, x); }
    bool same(int t, int x, int y) const { return find(t, x) == find(t, y); }
    bool same(int x, int y) const { return same(now, x, y); }
    int size(int t, int x) const {
        x = find(t, x);
        return prev(lower_bound(sz[x].begin(), sz[x].end(), make_pair(t + 1, 0)))->second;
    }
    int size(int x) const { return sz[find(x)].back().second; }
    bool unite(int x, int y) {
        ++now;
        if ((x = find(now, x)) == (y = find(now, y))) return 0;
        par[x] = max(par[x], par[y] + 1);
        par[y] = x;
        time[y] = now;
        sz[x].emplace_back(now, sz[x].back().second + sz[y].back().second);
        return 1;
    }
    bool uniteByRank(int x, int y) { return par[find(x)] < par[find(y)] ? unite(y, x) : unite(x, y); }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) cin >> A[i] >> B[i], A[i]--, B[i]--;

    PartiallyPersistentUnionFindTree ppuf;
    ppuf.build(N);
    for (int i = M - 1; i >= 0; --i) {
        ppuf.uniteByRank(A[i], B[i]);
    }

    ll ans = 0;
    for (int i = 0; i < M; ++i) {
        if (ppuf.same(M - i, A[i], B[i]) ^ ppuf.same(M - i - 1, A[i], B[i])) {
            int s = ppuf.size(M - i - 1, A[i]), t = ppuf.size(M - i - 1, B[i]);
            ans += (ll)s * t;
        }
        cout << ans << endl;
    }
}