#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int a, b, c;
  cin >> a >> b;
  double ans, ra, rb;
  ra = a;
  rb = b;
  ans = ra / rb;
  cout << fixed << setprecision(10) << ans;
  return 0;
}
