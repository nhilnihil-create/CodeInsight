// https://atcoder.jp/contests/abc090/tasks/arc091_b
#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using ll = long long;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k, ans = 0;
    cin >> n >> k;
    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }
    // 割る数はk+1以上
    FOR(d, k + 1, n + 1) {
        ans += n / d * (d - k);
        ans += max(0LL, n % d - k + 1);
        // cout << ans << endl;
    }
    cout << ans << endl;

    return 0;
}
