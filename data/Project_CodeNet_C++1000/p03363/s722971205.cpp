// https://atcoder.jp/contests/agc023/tasks/agc023_a
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
    int N, total = 0, ans = 0;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, int> mp;
    mp[0]++;
    for (auto &x : A) {
        cin >> x;
        total += x;
        mp[total]++;
    }
    for (auto &x : mp) {
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}
