#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  bool is_ordered = true;
  int prev = -1e6 - 5;
  int ma = -1e6 - 5;
  int ma_idx;
  int mi = 1e6 + 5;
  int mi_idx;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] > ma) {
      ma_idx = i;
      ma = a[i];
    }

    if (a[i] < mi) {
      mi_idx = i;
      mi = a[i];
    }
    if (a[i] < prev) is_ordered = false;
    prev = a[i];
  }

  if (is_ordered) {
    printf("%d\n", 0);
    return 0;
  }

  vector< pair<int, int> > ans;

  int add;
  int add_idx;
  bool reverse = false;
  if (abs(ma) >= abs(mi)) {
    add = ma;
    add_idx = ma_idx;
  } else {
    add = mi;
    add_idx = mi_idx;
    reverse = true;
  }
  for (int i = 0; i < n; ++i) ans.push_back(make_pair(add_idx + 1, i + 1));

  if (reverse) {
    for (int i = n - 1; i >= 1; --i) ans.push_back(make_pair(i + 1, i));
  } else {
    for (int i = 1; i < n; ++i) ans.push_back(make_pair(i, i + 1));
  }

  cout << ans.size() << endl;
  for (auto e: ans) cout << e.first << " " << e.second << endl;
  return 0;
}

