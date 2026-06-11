// https://atcoder.jp/contests/abc106/tasks/abc106_b
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int_fast32_t i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int_fast32_t i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

// 約数の個数 (１の倍数＋２の倍数＋３の倍数＋...)
template <int N> struct calc_approx {
    int cnt[N + 1] = {0};

    constexpr calc_approx() : cnt() {
        for (int_fast64_t i = 1; i <= N; ++i) {
            for (int_fast64_t j = i; j <= N; j += i)
                cnt[j]++;
        }
    }
};
calc_approx<200000> approx;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 105; i <= N; i += 2) {
        ans += (approx.cnt[i] == 8);
    }
    cout << ans << endl;
    return 0;
}
