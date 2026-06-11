#include <iostream>

using namespace std;

int digsum (int x) {
  int ans = 0;
  while (x != 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main () {
  int n;
  cin >> n;

  int ans = 1000;
  for (int a = 1; a < n; a++) {
    int b = n - a;
    ans = min(ans, digsum(a) + digsum(b));
  }

  cout << ans << endl;
}
