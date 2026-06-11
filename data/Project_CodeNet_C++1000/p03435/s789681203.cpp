#include <iostream>

using namespace std;

int main() {
  int c[3][3]{};
  for (auto &r : c)
    for (auto &e : r) cin >> e;

  bool flag{false};
  for (int a0 = 0; a0 <= c[0][0]; ++a0) {
    int b0 = c[0][0] - a0, b1 = c[1][0] - a0, b2 = c[2][0] - a0,
        a1 = c[0][1] - b0, a2 = c[0][2] - b0;
    if ((flag = a1 >= 0 && a2 >= 0 && a1 + b1 == c[1][1] &&
                a1 + b2 == c[2][1] && a2 + b1 == c[1][2] && a2 + b2 == c[2][2]))
      break;
  }
  cout << (flag ? "Yes" : "No") << endl;
}
