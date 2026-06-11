# include <iostream>
# include <cmath>
using namespace std;

int main() {
  int x; cin >> x;
  int ans = 0;
  for (int b = 1; b <= x; ++b) {
    for (int p = 2; p <= 10; ++p) {
      int exponential = pow(b, p);
      if (exponential <= x) ans = max(ans, exponential);
    }
  }
  cout << ans << endl;
  return 0;
}