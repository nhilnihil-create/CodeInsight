#include <iostream>

using namespace std;

int main () {
  int a, b, ab, x, y;
  cin >> a >> b >> ab >> x >> y;

  ab *= 2;
  ab = min(ab, a + b);
  a = min(a, ab);
  b = min(b, ab);

  int z = min(x, y);
  x -= z;
  y -= z;
  int ans = ab * z + a * x + b * y;
  cout << ans << endl;
}
