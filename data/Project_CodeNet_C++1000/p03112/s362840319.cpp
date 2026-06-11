#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<int64_t> s(a + 2, INF), t(b + 2, INF);
    for(int i = 0; i < a; ++i) cin >> s[i + 1];
    for(int i = 0; i < b; ++i) cin >> t[i + 1];
    s[0] = -INF;
    t[0] = -INF;
    while(q--) {
        int64_t x; cin >> x;
        auto sr = lower_bound(s.begin(), s.end(), x);
        auto sl = prev(sr);
        auto tr = lower_bound(t.begin(), t.end(), x);
        auto tl = prev(tr);
        auto d = [&](int64_t y) -> int64_t { return abs(x - y); };
        int64_t ans = min(max(d(*sr), d(*tr)), max(d(*sl), d(*tl)));
        ans = min(ans, 2 * d(*sl) + d(*tr));
        ans = min(ans, d(*sl) + 2 * d(*tr));
        ans = min(ans, 2 * d(*sr) + d(*tl));
        ans = min(ans, d(*sr) + 2 * d(*tl));
        cout << ans << '\n';
    }
    return 0;
}
