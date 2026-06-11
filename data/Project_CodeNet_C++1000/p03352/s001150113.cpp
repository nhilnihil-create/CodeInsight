#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int x;
  cin >> x;
  int ans = 1;
  for (int b = 2; b <= x; b++) {
    int p = b * b;
    for (int j = 0; ; j++) {
      if (p > x) break;
      ans = max(ans, p);
      p *= b;
    }
  }
  cout << ans << endl;
  return 0;
}