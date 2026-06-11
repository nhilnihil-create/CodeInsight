#include <iostream>
using namespace std;

int main() {
  int d, n;
  cin >> d >> n;
  int ans = 0;
  if (d == 0) {
    if (n == 100) {
      ans = 101;
    } else {
      ans = n;
    }
  }
  if (d == 1) {
    if (n == 100) {
      ans = 10100;
    } else {
      ans = n * 100;
    }
  }
  if (d == 2) {
    if (n == 100) {
      ans = 1010000;
    } else {
      ans = n * 10000;
    }
  }
  cout << ans << endl;
  return 0;
}
