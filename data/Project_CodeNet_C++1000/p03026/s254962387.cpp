#include <bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;
template <typename T> using vvec = vector<vector<T>>;

constexpr int64_t mpow(int64_t a, int64_t b, int64_t mod = 1000000007) {
    if (b <= 0) { return 1; } if (b == 1) { return a % mod; } if (b == 2) { return (a * a) % mod; }
    return (max(a * (b & 1), (int64_t)1) * mpow(mpow(a, b / 2, mod), 2, mod)) % mod;
}
constexpr int64_t mdiv(int64_t a, int64_t b, int64_t mod = 1000000007) {
    return (a * mpow(b, mod - 2, mod)) % mod;
}

void dfs(vvec<int> &g, vec<int> &c, vec<int> &v, int cv, int &cn) {
    if (v[cv] != -1) return;
    v[cv] = c[cn++];
    for (auto n : g[cv]) {
        dfs(g, c, v, n, cn);
    }
}

int main() {
    int n; cin >> n;
    vvec<int> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vec<int> c(n);
    for (auto &e : c) cin >> e;
    sort(c.rbegin(), c.rend());

    int cn = 0;
    vec<int> v(n, -1);
    dfs(g, c, v, 0, cn);

    int m = 0;
    for (int i = 1; i < n; ++i) m += c[i];
    cout << m << endl;
    for (int i = 0; i < n; ++i) {
        cout << v[i] << (i + 1 == n ? "" : " ");
    }
    cout << endl;
}

