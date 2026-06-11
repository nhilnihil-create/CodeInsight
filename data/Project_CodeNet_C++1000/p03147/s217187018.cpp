#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  int h[n];
  rep(i, n) cin >> h[i];
  int ans = 0;
  while (1) {
    int mini = 101;
    rep(i, n) {
      if (h[i] != 0) {
        mini = min(mini, h[i]);
        h[i]--;
        if (i == n - 1) ans++;
      } else {
        if (mini == 101)
          continue;
        else {
          ans++;
          mini = 101;
        }
      }
    }
    int sum = 0;
    rep(i, n) sum += h[i];
    if (sum == 0) break;
  }
  cout << ans << endl;
  return 0;
}