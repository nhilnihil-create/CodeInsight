/**
 *    author:  tourist
 *    created: 19.12.2019 14:51:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int low = 1, high = n;
  while (low < high) {
    int mid = (low + high) >> 1;
    vector<pair<int, int>> st;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      int diff = a[i] - (i == 0 ? 0 : a[i - 1]);
      if (diff > 0) {
        st.emplace_back(0, diff);
        continue;
      }
      while (diff < 0) {
        int take = min(st.back().second, -diff);
        diff += take;
        st.back().second -= take;
        if (st.back().second == 0) {
          st.pop_back();
        }
      }
      int k = 0;
      while (!st.empty() && st.back().first == mid - 1) {
        k += st.back().second;
        st.pop_back();
      }
      if (st.empty()) {
        ok = false;
        break;
      }
      int x = st.back().first;
      st.back().second -= 1;
      if (st.back().second == 0) {
        st.pop_back();
      }
      st.emplace_back(x + 1, 1);
      if (k > 0) {
        st.emplace_back(0, k);
      }
    }
    if (ok) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << low << '\n';
  return 0;
}
