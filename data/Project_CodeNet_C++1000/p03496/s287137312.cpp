#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  bool has_neg = false, has_pos = false;
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    if (va[i] >= 0) {
      has_pos = true;
    } else {
      has_neg = true;
    }
  }

  if (has_pos && !has_neg) {
    cout << n - 1 << '\n';
    for (int i = 0; i < n - 1; ++i) {
      cout << i + 1 << ' ' << i + 2 << '\n';
    }
    return 0;
  } else if (!has_pos && has_neg) {
    cout << n - 1 << '\n';
    for (int i = n - 1; i > 0; --i) {
      cout << i + 1 << ' ' << i << '\n';
    }
    return 0;
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
    return 0;
  } else if (max_a < 0) {
    for (int i = n - 1; i > 0; --i) {
      cout << i + 1 << ' ' << i << '\n';
    }
    return 0;
  }
}