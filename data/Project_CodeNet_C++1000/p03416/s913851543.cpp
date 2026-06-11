#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, m, c = 0;
  cin >> A >> B;
  for (int n = A; n <= B; n++) {
    if (n >= 10000) {
      if ((n % 10 == n / 10000) && ((n / 10) % 10 == (n / 1000) % 10)) {
        c++;
      }
    } else if (n >= 1000) {
      if ((n % 10 == n / 1000) && ((n / 10) % 10 == (n / 100) % 10)) {
        c++;
      }
    } else if (n >= 100) {
      if (n % 10 == n / 100) {
        c++;
      }
    } else if (n >= 10) {
      if (n % 10 == n / 10) {
        c++;
      }
    } else {
      c++;
    }
  }
  cout << c << endl;
}