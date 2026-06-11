#include <iostream>

using namespace std;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int m = max(a, max(b, c));
  int p = m;
  for (int i = 0; i < x; i++) {
    p *= 2;
  }
  int ans = a + b + c - m + p;
  cout << ans << endl;
  return 0;
}
