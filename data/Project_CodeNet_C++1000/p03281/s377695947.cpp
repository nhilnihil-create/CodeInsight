// https://atcoder.jp/contests/abc106/tasks/abc106_b
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

// N以下の約数の個数
vector<int> divisor_all(int n) {
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            v[j]++;
        }
    }
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    auto d = divisor_all(N);
    int cnt = 0;
    for (int i = 105; i <= N; i += 2) {
        cnt += d[i] == 8;
    }
    cout << cnt << endl;

    return 0;
}
