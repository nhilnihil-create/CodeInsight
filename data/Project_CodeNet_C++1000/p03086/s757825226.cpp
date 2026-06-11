// https://atcoder.jp/contests/abc122/tasks/abc122_b
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
    string S;
    cin >> S;
    int idx = 0, cnt = 0, tmp = 0;
    while (idx <= (int)S.length()) {
        if (S[idx] == 'A' || S[idx] == 'C' || S[idx] == 'G' || S[idx] == 'T') {
            tmp++;
        } else {
            cnt = max(cnt, tmp);
            tmp = 0;
        }
        idx++;
    }
    cnt = max(cnt, tmp);
    cout << cnt << endl;

    return 0;
}
