#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


struct UnionFind {
    vll par;
    vll _size;

    UnionFind(ll N) : par(N), _size(N, 1) {
        rep(i, N) par[i] = i;
    }

    ll root(ll x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
        _size[ry] += _size[rx];
        _size[rx] = 0;
    }

    bool same(ll x, ll y) {
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll size(ll x) {
        return _size[root(x)];
    }
};

ll comb(ll n) {
    return n * (n - 1) / 2;
}

int main()
{
    ll N, M; cin >> N >> M;
    UnionFind uf(N);
    vll A(M), B(M); rep(i, M) {
        cin >> A[i] >> B[i]; A[i]--, B[i]--;
    }

    vll ans(M);
    ll ucomf = N * (N - 1) / 2;
    for (ll i = M - 1; i >= 0; i--) {
        ll a = A[i], b = B[i];
        ans[i] = ucomf;
        if (!uf.same(a, b)) ucomf -= (comb(uf.size(a) + uf.size(b)) - comb(uf.size(a)) - comb(uf.size(b)));
        uf.unite(a, b);
    }
    for (auto elme : ans) {
        cout << elme << endl;
    }
    return 0;
}