#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<ll> d;
    UnionFind(ll n = 0): d(n, -1) {}
    ll find(ll x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(ll x, ll y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(ll x, ll y) { return find(x) == find(y); }
    ll size(ll x) { return -d[find(x)]; }
};

int main() {
    ll N, M; cin >> N >> M;
    vector<ll> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    vector<ll> ans(M);
    ll cnt = N * (N-1) / 2;
    UnionFind uf(N);
    for (int i = M-1; i >= 0; i--) {
        ans[i] = cnt;
        if (!uf.same(A[i], B[i])) {
            cnt -= uf.size(A[i]) * uf.size(B[i]);
            uf.unite(A[i], B[i]); 
        }
    }
    for (int i = 0; i < M; i++) cout << ans[i] << endl;
    return 0;
}