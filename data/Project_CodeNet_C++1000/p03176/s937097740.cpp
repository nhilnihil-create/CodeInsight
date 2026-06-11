#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int64_t seg[2 * N] = {0};
int64_t dp[N] = {0};
int h[N], v[N];
int n;

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
   for (int i = 1; i <= n; ++i) dp[h[i]] = v[i];
   for (int i = 1; i <= n; ++i) {
      int64_t mx_val = query(1, h[i]);
      dp[h[i]] = max(dp[h[i]], mx_val + v[i]);
      modify(h[i], dp[h[i]]);
   }
   cout << *max_element(begin(dp), end(dp));
}

signed main() {
   cin >> n;
   for (int i = 1; i <= n; ++i) cin >> h[i];
   for (int i = 1; i <= n; ++i) cin >> v[i];
   solve();

   return 0;
}
