#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int64_t seg[2 * N] = {0};
int64_t dp[N] = {0};
int h[N], v[N];
int n;

// void modify(int64_t l, int64_t r, int64_t idx, int64_t x, int64_t val) {
//    if (l > idx || r < idx) return;
//    if (l == r) {
//       seg[x] = max(seg[x], val);
//       return;
//    }
//    int64_t mid = (l+r)/2;
//    modify(l, mid, idx, x + x + 1, val);
//    modify(mid + 1, r, idx, x + x + 2, val);
//    seg[x] = max(seg[x + x + 1], seg[x + x + 2]);
// }

// int64_t query(int64_t l, int64_t r, int64_t ql, int64_t qr, int64_t x) {
//    if (r < ql || l > qr) return int64_t32_MIN;
//    if (l >= ql && r <= qr) return seg[x];
//    int64_t mid = (l+r)/2;
//    int64_t left = query(l, mid, ql, qr, x + x + 1);
//    int64_t right = query(mid + 1, r, ql, qr, x + x + 2);
//    return max(left, right);
// }

void modify(int p, int64_t value) {  // set value at position p
  for (seg[p += n] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p], seg[p^1]);
  // changing the parent seg[p] left child, seg[p^1] right child and vice versa
}

int64_t query(int l, int r) {  // sum on int64_terval [l, r)
  int64_t res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, seg[l++]);
    if (r&1) res = max(res, seg[--r]);
  }
  return res;
}

void solve() {
//    for (int64_t i = 1; i <= n; ++i) dp[h[i]] = v[i];
//    for (int64_t i = 1; i <= n; ++i) {
//       int64_t mx_val = query(1, n, 1, h[i]-1, 0);
//       dp[h[i]] = max(dp[h[i]], mx_val + v[i]);
//       modify(1, n, h[i], 0, dp[h[i]]);
//    }

   for (int i = 1; i <= n; ++i) dp[h[i]] = v[i];
   for (int i = 1; i <= n; ++i) {
      int64_t mx_val = query(1, h[i]);
      dp[h[i]] = max(dp[h[i]], mx_val + v[i]);
      modify(h[i], dp[h[i]]);
   }

   int64_t ans = 0;
   for (int64_t i = 1; i <= n; ++i) {
      ans = max(dp[i], ans);
   }
   cout << ans << '\n';

//    for (int i = 1; i <= 2 * n; ++i) {
//       cout << dp[i] << ' ';
//    }
}

signed main() {
   cin >> n;
   for (int i = 1; i <= n; ++i) cin >> h[i];
   for (int i = 1; i <= n; ++i) cin >> v[i];
   solve();

   return 0;
}
