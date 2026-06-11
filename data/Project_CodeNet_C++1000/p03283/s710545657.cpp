// https://atcoder.jp/contests/abc106/tasks/abc106_d
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

// 二次元BIT
// source: https://iq.opengenus.org/2d-fenwick-tree/

// 2D fenwick tree for sub-matrix sum problem
class FenwickTree {
  private:
    // Matrix to store the tree
    std::vector<std::vector<int>> ft;

  public:
    // Function to get least significant bit
    int LSB(int x) { return x & (-x); }

    int query(int x, int y) {
        int sum = 0;
        for (int x_ = x; x_ > 0; x_ = x_ - LSB(x_)) {
            for (int y_ = y; y_ > 0; y_ = y_ - LSB(y_)) {
                sum = sum + ft[x_][y_];
            }
        }
        return sum;
    }

    int query(int x1, int y1, int x2, int y2) {
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) +
                query(x1 - 1, y1 - 1));
    }

    void update(int x, int y, int value) {
        // also update matrix[x][y] if needed.
        for (int x_ = x; x_ < (int)ft.size(); x_ = x_ + LSB(x_)) {
            for (int y_ = y; y_ < (int)ft[0].size(); y_ = y_ + LSB(y_)) {
                ft[x_][y_] += value;
            }
        }
    }

    FenwickTree(std::vector<std::vector<int>> matrix) {
        // 引用元のコードはn, mが逆転してバグっているので修正
        int n = matrix.size();
        // matrix must not be empty.
        int m = matrix[0].size();
        // Initialize matrix ft
        ft.assign(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                update(i + 1, j + 1, matrix[i][j]);
        }
    }

    FenwickTree(int h, int w) { ft.assign(h + 1, std::vector<int>(w + 1, 0)); }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    FenwickTree ft(N, N);
    REP(i, M) {
        int l, r;
        cin >> l >> r;
        ft.update(l, r, 1);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << ft.query(l, l, r, r) << "\n";
    }

    return 0;
}
