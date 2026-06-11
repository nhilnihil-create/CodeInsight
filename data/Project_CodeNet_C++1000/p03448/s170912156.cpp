#include <iostream>

using namespace std;

int main() {
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int res = 0;
  for (int i = 0; i <= A; ++i) {
    if (500 * i + 100 * B + 50 * C < X) continue;
    if (X < 500 * i) break;;
    for (int j = 0; j <= B; ++j) {
      if (500 * i + 100 * j + 50 * C < X) continue;
      if (X < 500 * i + 100 * j) break;;
      for (int k = 0; k <= C; ++k) {
        if (X <= 500 * i + 100 * j + 50 * k) {
          res += (500 * i + 100 * j + 50 * k == X);
          break;
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}
