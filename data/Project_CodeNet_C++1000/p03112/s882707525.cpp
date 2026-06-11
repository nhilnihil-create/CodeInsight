#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1LL << 60;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<int64_t> S(A + 2, -INF), T(B + 2, -INF);
    for(int i = 0; i < A; ++i) cin >> S[i + 2];
    for(int i = 0; i < B; ++i) cin >> T[i + 2];
    S.push_back(INF);
    S.push_back(INF);
    T.push_back(INF);
    T.push_back(INF);
    while(Q--) {
        int64_t x; cin >> x;
        auto d = [&](int64_t p) -> int64_t { return abs(x - p); };
        auto sr = lower_bound(S.begin(), S.end(), x);
        auto sl = prev(sr);
        auto tr = lower_bound(T.begin(), T.end(), x);
        auto tl = prev(tr);
        int64_t ans = min(max(d(*sr), d(*tr)), max(d(*sl), d(*tl)));
        ans = min(ans, 2 * d(*sr) + d(*tl));
        ans = min(ans, d(*sr) + 2 * d(*tl));
        ans = min(ans, 2 * d(*tr) + d(*sl));
        ans = min(ans, d(*tr) + 2 * d(*sl));
        cout << ans << '\n';
    }
    return 0;
}
