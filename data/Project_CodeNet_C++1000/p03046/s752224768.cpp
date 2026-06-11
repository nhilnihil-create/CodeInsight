#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int m, k;
  cin >> m >> k;

  int max_a = pow(2, m);
  if (max_a <= k) {
    cout << -1 << '\n';
    return 0;
  }

  if (m == 0) {
    if (k == 0) {
      cout << "0 0" << '\n';
    } else {
      cout << -1 << '\n';
    }

    return 0;
  }

  if (m == 1) {
    if (k == 0) {
      cout << "0 0 1 1" << '\n';
    } else {
      cout << -1 << '\n';
    }

    return 0;
  }

  for (int i = 0; i < max_a; ++i) {
    if (i == k) {
      continue;
    }

    cout << i << ' ';
  }

  cout << k << ' ';

  for (int i = max_a - 1; i >= 0; --i) {
    if (i == k) {
      continue;
    }

    cout << i << ' ';
  }

  cout << k << '\n';
}