#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> h(n+2);
  h[0] = 0;
  h[n+1] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  bool up = false;
  int ans = 0;
  int bottom = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (h[i-1] < h[i] && !up) {
      up = true;
      bottom = h[i - 1];
    }
    else if (h[i-1] > h[i] && up) {
      up = false;
      ans += h[i - 1] - bottom;
    }
  }

  cout << ans << endl;
  return 0;
}