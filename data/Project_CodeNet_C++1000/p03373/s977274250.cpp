// https://atcoder.jp/contests/arc096/tasks/arc096_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int ans = INT32_MAX;
    ans = min(ans, A * X + B * Y);
    // ABピザを買う枚数
    int t = min(X, Y) * 2;
    ans = min(ans, C * t + A * (X - t / 2) + B * (Y - t / 2));
    t = max(X, Y) * 2;
    ans = min(ans, C * t + A * max(0LL, X - t / 2) + B * max(0LL, Y - t / 2));
    cout << ans << endl;

    return 0;
}
