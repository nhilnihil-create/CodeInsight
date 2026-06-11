#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  auto max_abs = [&]() {
    int max_a = va.front(), idx = 0;
    for (int i = 0; i < va.size(); ++i) {
      if (abs(max_a) < abs(va[i])) {
        max_a = va[i];
        idx = i;
      }
    }

    return idx;
  };

  int idx = max_abs();
  int max_a = va[idx];
  cout << (n - 1) * 2 << '\n';
  for (int i = 0; i < n; ++i) {
    if (idx != i) {
      cout << idx + 1 << ' ' << i + 1 << '\n';
    }
  }

  if (max_a >= 0) {
    for (int i = 0; i < n - 1; ++i) {
      cout << i + 1 << ' ' << i + 2 << '\n';
    }
  } else if (max_a < 0) {
    for (int i = n - 1; i > 0; --i) {
      cout << i + 1 << ' ' << i << '\n';
    }
  }
  return 0;
}