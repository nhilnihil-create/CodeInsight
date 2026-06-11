#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
struct BIT {
    vector<LL> bit; int n;
    void init(int _n) {
        n = _n;
        bit.clear(); bit.resize(n + 1, 0);
    }
    LL q(int x) {
        LL ret = 0;
        while (x > 0) {
            ret = max(ret, bit[x]);
            x -= x & (-x);
        }
        return ret;
    }
    void m(int x, LL v) {
        while (x <= n) {
            bit[x] = max(bit[x], v);
            x += x & (-x);
        }
    }
} solver;
void marmot0814() {
    int n; cin >> n;
    solver.init(n);
    vector<int> h(n);
    for (auto &v : h) cin >> v;
    vector<LL> a(n);
    for (auto &v : a) cin >> v;
    LL ans = 0;
    for (int i = 0 ; i < n ; i++) {
        LL x = solver.q(h[i]);
        ans = max(ans, x + a[i]);
        solver.m(h[i], x + a[i]);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}