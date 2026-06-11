#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans, used(n, 0);
  for (int i = 0; i < n; i++) {
    int k = 1, num = 0, id = 0;
    for (int j = 0; j < n; j++) {
      if (used[j]) continue;
      if (a[j] == k) num = k, id = j;
      k++;
    }
    if (num == 0) {
      cout << -1 << endl;
      return 0;
    }
    used[id] = 1;
    ans.emplace_back(num);
  }
  reverse(ans.begin(), ans.end());
  for (auto &v : ans) {
    cout << v << endl;
  }

  return 0;
}