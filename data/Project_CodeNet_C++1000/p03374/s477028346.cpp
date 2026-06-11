#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

template<typename T>
struct sparse_table {
    vector<vector<T>> st;

    sparse_table(const vector<T>& a) {
        const int w = lg(a.size());
        st.reserve(w);
        st.emplace_back(a);
        for (int k = 1; k < w; k++) {
            st.emplace_back(vector<T>(a.size() - (1 << k) + 1));
            for (int i = 0; i < (int) a.size() - (1 << k) + 1; i++)
                st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
        }
    }

    inline int lg(T n) {
        return 64 - __builtin_clzll(n);
    }

    inline T query(int l, int r) {
        if (l > r) return 0;
        int k = lg(r - l + 1) - 1;
        return max(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //    freopen("out", "w", stdout);
#endif
    //    ios::sync_with_stdio(0), cin.tie(0);
    ll n, c;
    scanf("%lld%lld", &n, &c);
    vector<ll> x(n), v(n), F(n), B(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &v[i]);
    }

    F[0] = v[0];
    for (int i = 1; i < n; i++)
        F[i] = F[i - 1] + v[i];
    for (int i = 0; i < n; i++)
        F[i] -= x[i];

    B[0] = v[n - 1];
    for (int i = 1; i < n; i++)
        B[i] = B[i - 1] + v[n - i - 1];
    for (int i = 0; i < n; i++)
        B[i] -= (c - x[n - i - 1]);

    sparse_table<ll> fst(F), bst(B);

    ll ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll cur = max(F[i], F[i] + bst.query(0, n - 2 - i) - x[i]);
        ans = max(ans, cur);
    }

    ll res = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        ll cur = max(B[i], B[i] + fst.query(0, n - 2 - i) - (c - x[n - i - 1]));
        res = max(res, cur);
    }

    cout << max({0LL, res, ans}) << endl;

    return 0;
}
