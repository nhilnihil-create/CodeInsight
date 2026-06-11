#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int64_t ans = 100000000000;
  for (int64_t i = 0; i <= max(X, Y); i++) {
    int64_t a, b, ab, zero;
    zero = 0;
    a = max(X-i, zero);
    b = max(Y-i, zero);
    ab = 2*i;
    ans = min(ans, A*a + B*b + C*ab);
  }
  cout << ans << endl;
}