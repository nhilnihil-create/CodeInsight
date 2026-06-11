#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> c(3 * 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c.at(i * 3 + j);
    }
  }
  vector<bool> flag(3, false);
  bool ans = false;
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      for (int k = 0; k < 101; k++) {
        if (((c.at(0 * 3 + 0) - i == c.at(0 * 3 + 1) - j) &&
             (c.at(0 * 3 + 1) - j == c.at(0 * 3 + 2) - k)) &&
            ((c.at(1 * 3 + 0) - i == c.at(1 * 3 + 1) - j) &&
             (c.at(1 * 3 + 1) - j == c.at(1 * 3 + 2) - k)) &&
            ((c.at(2 * 3 + 0) - i == c.at(2 * 3 + 1) - j) &&
             (c.at(2 * 3 + 1) - j == c.at(2 * 3 + 2) - k))) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}