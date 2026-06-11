#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string abcd;
  cin >> abcd;
  for (int bit = 0; bit < (1 << 3); bit++) {
    int sum = abcd[0] - '0';
    for (int i = 0; i < 3; i++) {
      if (bit & (1 << i)) {
        sum += abcd[i + 1] - '0';
      }
      else {
        sum -= abcd[i + 1] - '0';
      }
    }
    if (sum == 7) {
      cout << abcd[0];
      for (int i = 0; i < 3; i++) {
        if (bit & (1 << i)) {
          cout << "+";
        }
        else {
          cout << "-";
        }
        cout << abcd[i + 1];
      }
      cout << "=7" << endl;
      break;
    }
  }
  return 0;
}
