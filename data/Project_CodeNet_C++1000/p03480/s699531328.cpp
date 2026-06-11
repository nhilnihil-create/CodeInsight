// https://atcoder.jp/contests/abc083/tasks/arc088_b
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.length(), ans = len;
    FOR(i, 1, s.length()) {
        if (s[i] != s[i - 1]) {
            ans = min(ans, max(i, len - i));
        }
    }
    cout << ans << endl;

    return 0;
}
