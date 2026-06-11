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

// BIT(Binary-Indexed-Tree) 別名：Fenwick Tree
template <typename T> struct BIT {
    int n;
    vector<T> d;
    BIT(int n = 0) : n(n), d(n + 1) {}
    // 要素iにxを加算
    void add(int i, T x = 1) {
        for (i++; i <= n; i += i & -i) {
            d[i] += x;
        }
    }
    // 区間[0, i]の合計を求める（閉区間）
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i & -i) {
            x += d[i];
        }
        return x;
    }
    // 区間[l, r]の合計を求める（閉区間）
    T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

const int SZ = 1e5 + 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    constexpr auto p = Prime<SZ>();
    BIT<int> bit(SZ);
    for (int i = 1; i < SZ; i += 2) {
        if (p.sieve[i] && p.sieve[(i + 1) / 2]) {
            bit.add(i, 1);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << bit.sum(l, r + 1) << endl;
    }

    return 0;
}
