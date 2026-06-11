#include <iostream>

using namespace std;

int main() {
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int ans = 0;
  for (int i = 0; i <= 3000; ++i) {
    for (int j = 0; j <= 3000; ++j) {
      int k = (n - (i * r + j * g)) / b;
      if (0 <= k && r * i + g * j + b * k == n)
        ++ans;
    }
  }
  cout << ans << endl;
}
