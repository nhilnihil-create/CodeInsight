#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  vector<int> balls(200000);
  rep(i, n) balls.at(a.at(i))++;
  sort(balls.begin(), balls.end());

  int kind = 0;
  rep(i, balls.size()) {
    if (balls.at(i) > 0)
      kind++;
  }

  int ans = 0;
  rep(i, balls.size()) {
    if (kind <= k) break;
    if (balls.at(i) > 0) {
      ans += balls.at(i);
      kind--;
    }
  }

  cout << ans << endl;
  return 0;
}