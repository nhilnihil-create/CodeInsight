#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

struct V {
    ll val;
    int l, m, n;

    V(ll val = 0, int l = 0, int m = 0, int n = 0) : val(val), l(l), m(m), n(n) {}
    bool const operator<(const V& v) const { return val < v.val; }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vll a(x), b(y), c(z);
    rep(i, 0, x) { cin >> a[i]; }
    rep(i, 0, y) { cin >> b[i]; }
    rep(i, 0, z) { cin >> c[i]; }

    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    sort(all(c), greater<ll>());

    vector<vvb> seen(x, vvb(y, vb(z, false)));
    seen[0][0][0] = true;

    priority_queue<V> pq;
    pq.emplace(a[0] + b[0] + c[0], 0, 0, 0);

    rep(_, 0, k) {
        V p = pq.top();
        pq.pop();
        cout << p.val << endl;

        if (p.l + 1 < x && !seen[p.l + 1][p.m][p.n]) {
            pq.emplace(a[p.l + 1] + b[p.m] + c[p.n], p.l + 1, p.m, p.n);
            seen[p.l + 1][p.m][p.n] = true;
        }

        if (p.m + 1 < y && !seen[p.l][p.m + 1][p.n]) {
            pq.emplace(a[p.l] + b[p.m + 1] + c[p.n], p.l, p.m + 1, p.n);
            seen[p.l][p.m + 1][p.n] = true;
        }

        if (p.n + 1 < z && !seen[p.l][p.m][p.n + 1]) {
            pq.emplace(a[p.l] + b[p.m] + c[p.n + 1], p.l, p.m, p.n + 1);
            seen[p.l][p.m][p.n + 1] = true;
        }
    }

    return 0;
}