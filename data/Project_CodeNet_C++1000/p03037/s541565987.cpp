#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
  }
  int min_r = *min_element(r.begin(), r.end());
  int max_l = *max_element(l.begin(), l.end());
  cout << max(0, min_r - max_l + 1) << '\n';
  return 0;
}