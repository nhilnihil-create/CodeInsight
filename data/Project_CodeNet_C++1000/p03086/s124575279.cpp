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
    string str;
    cin >> str;
    regex patern("[ACGT]+");
    smatch match;

    size_t maxv = 0;
    while (regex_search(str, match, patern)) {
        maxv = max(maxv, match.str().length());
        str = match.suffix();
    }
    cout << maxv << endl;

    return 0;
}
