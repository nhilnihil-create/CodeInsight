// https://atcoder.jp/contests/abc106/tasks/abc106_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int_fast32_t i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int_fast32_t i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

vector<int> a = {105, 135, 165, 189, 195};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    auto it = lower_bound(ALL(a), N + 1);
    cout << distance(a.begin(), it) << endl;
    return 0;
}
