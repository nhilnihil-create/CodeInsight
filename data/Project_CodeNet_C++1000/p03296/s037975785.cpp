// https://atcoder.jp/contests/agc026/tasks/agc026_a
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, ans = 0;
    cin >> N;
    vector<int> v(N);
    for (auto &x : v)
        cin >> x;
    REP(i, N - 1) {
        if (v[i] == v[i + 1]) {
            v[i + 1] = -v[i + 1];
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
