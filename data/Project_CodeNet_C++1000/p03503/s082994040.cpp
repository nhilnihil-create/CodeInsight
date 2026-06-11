#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll INF = 1101101101101;
typedef pair<int, int> P;

int main() {
  int n;
  cin >> n;
  int f[n][10];
  rep(i, n) rep(j, 10) cin >> f[i][j];
  int p[n][10];
  rep(i, n) rep(j, 11) cin >> p[i][j];
  ll ma = -INF;

  for (int bit = 0; bit < (1 << 10); ++bit) {
    bool ok = true;
    vector<int> a(n);
    for (int i = 0; i < 10; ++i) {
      rep(t, n) {
        if (bit & (1 << i) && f[t][i] == 1) {
          ok = false;
          a[t]++;
        }
      }
      ll total = 0;
      rep(i, n) total += p[i][a[i]];
      if (ok) continue;
      ma = max(total, ma);
    }
  }
  cout << ma << endl;
}