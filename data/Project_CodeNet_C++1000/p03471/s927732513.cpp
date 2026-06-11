#include <iostream>
using namespace std;
int main() {
  int n, y;

  cin >> n >> y;
  int flag = 0;
  int a_max = y / 10000;
  for (int a = a_max; a >= 0; a--) {
    int b_max = n - a;
    for (int b = b_max; b >= 0; b--) {
      int c = n - a - b;
      // cout << "::" << a << " " << b << " " << c << endl;
      if (y == 10000 * a + 5000 * b + 1000 * c) {
        // bingo
        cout << a << " " << b << " " << c << endl;
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  if (flag == 0) {
    cout << "-1 -1 -1" << endl;
  }

  return 0;
}