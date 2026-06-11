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

vector<int64_t> divisor(int64_t n) {
    vector<int64_t> ret;
    for (int64_t i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 105; i <= N; i += 2) {
        auto t = divisor(i);
        cnt += t.size() == 8;
    }
    cout << cnt << endl;

    return 0;
}
