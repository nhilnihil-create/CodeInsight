#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w, dh, dw;
  cin >> h >> w >> dh >> dw;
  int ans;
  ans = h * w;
  ans -= dh * w + dw * h;
  ans += dh * dw;
  cout << ans << endl;

  return 0;
}
