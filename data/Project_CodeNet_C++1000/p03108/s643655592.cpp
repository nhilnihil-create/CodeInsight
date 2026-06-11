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

ll mod = 1e9+7;

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

ll modinv(ll a, ll m) {
    ll x = a, y = m, u = 1, v = 0;
    while (y) {
        ll div = x / y;
        x -= div * y; swap(x, y);
        u -= div * v; swap(u, v);
    }
    return (u % m + m) % m;
}

ll comb(ll n, ll k) {
    ll dividend = 1, divisor = 1;
    rep(i, k) {
        dividend = (dividend * (n - i)) % mod;
        divisor = (divisor * modinv(i + 1, mod)) % mod;
    }
    return (dividend * divisor) % mod;
}

int main()
{
    ll N, M; cin >> N >> M;
    UnionFind uf(N);
    vll A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }

    vll ans(M, 0);
    ll origin = N * (N - 1) / 2;
    for (ll i = M - 1; i >= 0; i--) {
        ll a = A[i], b = B[i];
        ans[i] = origin;
        if (!uf.same(a, b)) origin -= uf.size(a) * uf.size(b);
        uf.unite(a, b);
    }

    for (auto elem : ans) {
        cout << elem << endl;
    }
    return 0;
}
