#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, t, a;
  cin >> n >> t >> a;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int ans = 0;
  int mn = 1 << 30;
  rep(i, n) {
    int c = t * 1000 - h[i] * 6;
    int dc = abs(1000 * a - c);
    if (dc < mn)  {
      mn = dc;
      ans = i;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}