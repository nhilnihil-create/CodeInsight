#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  int res = 0;
  while (!st.empty()) {
    int x = *st.rbegin();
    st.erase(--st.end());
    int y = 1; while (y < x) y += y;
    int z = (__builtin_popcount(x) == 1 ? x : y - x);
    if (st.count(z)) {
      st.erase(st.find(z));
      ++res;
    }
  }
  cout << res << '\n';
  return 0;
}
