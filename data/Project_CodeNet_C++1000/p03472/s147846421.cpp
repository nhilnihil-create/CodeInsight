#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];

  int max_a = *max_element(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  ll d = 0;
  int natk = 0;
  rep(i, n) {
    if (d >= h) {
      printf("%d\n", natk);
      return 0;
    }
    if (b[i] <= max_a) break;
    d += b[i];
    ++natk;
  }
  natk += (h - d + max_a - 1) / max_a;
  printf("%d\n", natk);
  return 0;
}