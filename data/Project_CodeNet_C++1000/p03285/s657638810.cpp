#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int maxfour = n / 4;
  int maxsvn = n / 7;
  bool flagans = false;
  for (int i = 0; i < maxfour + 1; ++i) {
    for (int j = 0; j < maxsvn + 1; ++j) {
      if (n == 4 * i + 7 * j) {
        flagans = true;
        break;
      }
    }
  }
  if (flagans)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}