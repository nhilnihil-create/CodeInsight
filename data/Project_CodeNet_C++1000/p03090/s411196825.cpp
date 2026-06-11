#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  auto print = [&](int i, int j) {
    if (n % 2 == 0) {
      return i + j != n + 1;
    } else {
      return i + j != n;
    }
  };

  int m = n * (n - 1) / 2 - n / 2;
  cout << m << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (print(i, j)) {
        cout << i << " " << j << endl;
      }
    }
  }
}