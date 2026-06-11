//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
  int r, g, b, n, ans = 0;
  cin >> r >> g >> b >> n;
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      if (n-r*i-g*j < 0) break;
      if ((n-r*i-g*j) % b == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}