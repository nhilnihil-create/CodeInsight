#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a(2e5 + 2);

bool check(int k) {
  vector<pair<int, int>> st;
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1]) {
      if (k == 1){
        return false;
      }
      while (!st.empty() && st.back().first > a[i]){
          st.pop_back();
      }
      int cur = a[i];
      while(!st.empty() && st.back().first == cur && st.back().second == k - 1) {
        st.pop_back();
        cur--;
      }
      if (cur < 1) {
        return false;
      }
      if (st.empty() || st.back().first < cur) {
        st.emplace_back(cur, 1);
      } else {
        st.back().second++;
      }
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int lb = 0;
  int ub = n + 1;
  int mid;
  while (ub - lb > 1){
      mid = (ub + lb) >> 1;
      if (check(mid)) {
          ub = mid;
      } else {
        lb = mid;
      }
  }
  cout << ub << '\n';

  return 0;
}