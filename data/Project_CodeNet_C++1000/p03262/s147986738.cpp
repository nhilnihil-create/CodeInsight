#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int N, X, ans, x;
  cin >> N >> X >> x;
  ans = abs(x - X);
  while (cin >> x) ans = gcd(ans, abs(x - X));
  cout << ans << endl;
}
