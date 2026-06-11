// https://atcoder.jp/contests/abc084/tasks/abc084_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

// constexprな素数列挙(エラトステネスの篩)
// https://259-momone.hatenablog.com/entry/2018/05/06/015026
template <int_fast64_t max_N> struct Prime {
    bool sieve[max_N];
    constexpr Prime() : sieve() {
        for (int_fast64_t i = 0; i < max_N; ++i)
            sieve[i] = true;
        sieve[0] = sieve[1] = false;
        for (int_fast64_t i = 2; i < max_N; ++i) {
            for (int_fast64_t j = i * i; j < max_N; j += i)
                sieve[j] = false;
        }
    }
};

const int SZ = 1e5 + 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    constexpr auto p = Prime<SZ>();
    vector<int> cnt(SZ + 1);
    cnt[0] = 0;
    for (int i = 1; i < SZ; i++) {
        cnt[i] = cnt[i - 1];
        if (p.sieve[i] && p.sieve[(i + 1) / 2]) {
            cnt[i]++;
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << cnt[r] - cnt[l - 1] << "\n";
    }

    return 0;
}
