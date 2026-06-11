// https://atcoder.jp/contests/abc106/tasks/abc106_b
#include <bits/stdc++.h>
using namespace std;
using P = pair<double, int>;
#define REP(i, n) FOR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// 約数の列挙
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

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    if (n < 105) {
        cout << "0\n";
        return 0;
    } else {
        for (int i = 105; i <= n; i += 2) {
            auto t = divisor(i);
            if (t.size() == 8) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
