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

// 約数の個数
template <int_fast64_t max_N> struct Prime {
    int cnt[max_N] = {0};
    constexpr Prime() : cnt() {
        for (int_fast64_t i = 1; i < max_N; ++i) {
            for (int_fast64_t j = i; j < max_N; j += i)
                cnt[j]++;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    constexpr auto d = Prime<65535>();
    int cnt = 0;
    for (int i = 105; i <= N; i += 2) {
        cnt += d.cnt[i] == 8;
    }
    cout << cnt << endl;

    return 0;
}
