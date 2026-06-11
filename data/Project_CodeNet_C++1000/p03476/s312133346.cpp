// https://atcoder.jp/contests/abc084/tasks/abc084_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()

const int SZ = 1e5;

// constexprな素数列挙(エラトステネスの篩)
// https://259-momone.hatenablog.com/entry/2018/05/06/015026
template <int N> struct Prime {
    bool b[N + 1]; // trueなら素数
    constexpr Prime() : b() {
        fill_n(b, N + 1, true);
        b[0] = b[1] = false;
        for (int_fast64_t i = 2; i <= N; ++i) {
            if (b[i]) {
                for (int_fast64_t j = i * i; j <= N; j += i) {
                    b[j] = false;
                }
            }
        }
    }
};
Prime<SZ> prime;

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
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    BIT<int> bit(SZ);
    for (int i = 1; i < SZ; i += 2) {
        if (prime.b[i] && prime.b[(i + 1) / 2]) {
            bit.add(i, 1);
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << bit.sum(r) - bit.sum(l - 1) << "\n";
    }

    return 0;
}
