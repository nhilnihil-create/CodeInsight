#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5, LG = 28, A = 1 << LG;

int n, a[N], b[N];
vector<int> bit0, bit1;

int count(int l, int r, vector<int> &v) {
  if (l > r) return 0;
  return upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  int ans = 0;
  for (int mod = 1, bit = 0; mod <= A; mod <<= 1, ++bit) {
    bit0.clear(); bit1.clear();
    for (int i = 1; i <= n; ++i) {
      if ((b[i] / mod) & 1)
        bit1.emplace_back(b[i] % mod);
      else
        bit0.emplace_back(b[i] % mod);
    }
    sort(bit0.begin(), bit0.end());
    sort(bit1.begin(), bit1.end());

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      int rem = a[i] % mod;
      if ((a[i] / mod) & 1) {
        (cnt += count(0, mod - 1 - rem, bit0)) %= 2;
        (cnt += count(mod - rem, mod - 1, bit1)) %= 2;
      } else {
        (cnt += count(0, mod - 1 - rem, bit1)) %= 2;
        (cnt += count(mod - rem, mod - 1, bit0)) %= 2;
      }
    }
    if (cnt & 1) ans += 1 << bit;
  }
  cout << ans;
  return 0;
}