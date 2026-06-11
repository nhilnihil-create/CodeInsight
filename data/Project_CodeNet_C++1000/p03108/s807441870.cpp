#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct UnionFind {
    vector<ll> d;
    UnionFind(ll n = 0) : d(n,-1) {}
    ll find(ll x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(ll x, ll y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x,y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(ll x, ll y) { return find(x) == find(y); }
    ll size(ll x) { return -d[find(x)]; }
};


int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    UnionFind uf(n);
    vector<ll> ans;
    ll now = n * (n - 1) / 2;
    for (ll i = m - 1; i >= 0; --i) {
        ans.emplace_back(now);
        ll x = a[i], y = b[i];
        if (!uf.same(x, y)) {
            now -= uf.size(x) * uf.size(y);
        }
        uf.unite(x, y);
    }
    reverse(ans.begin(), ans.end());
    for (ll i : ans) cout << i << endl;
}
