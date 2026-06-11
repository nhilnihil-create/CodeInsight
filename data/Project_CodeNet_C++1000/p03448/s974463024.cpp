#include <iostream>

using namespace std;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int cnt = 0;
  for (int i = 0; i <= a; ++i) {
    int _x = x - i * 500;
    if (_x < 0) break;
    for (int j = 0; j <= b; ++j) {
      int __x = _x - j * 100;
      if (__x < 0) break;
      if (__x / 50 <= c) cnt++;
    }
  }
  cout << cnt << endl;
}
