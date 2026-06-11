#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;

  bool canBuy = false;
  for (int i = 0; i <= 25; i++) {
    for (int j = 0; j <= 15; j++) {
      int total = 4 * i + 7 * j;
      if (total == n) {
        canBuy = true;
      }
    }
  }

  if (canBuy) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}