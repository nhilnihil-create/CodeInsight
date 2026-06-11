#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  if (n >= 24) {
    cout << "0\n";
    return 0;
  }
  
  vector<int> d(n);
  for (int i = 0; i < n; i++) cin >> d.at(i);
  sort(d.begin(), d.end());
  
  vector<int> a = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12};
  if (d == a) {
    cout << "1\n";
    return 0;
  }
  else if (n == 23) {
    cout << "0\n";
    return 0;
  }
  
  vector<int> e(n);
  for (int i = 0; i < n; i++) e.at(i) = 24 - d.at(i);
  
  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
      if (bit & (1 << i)) x.at(i) = d.at(i);
      else x.at(i) = e.at(i);
    }
    sort(x.begin(), x.end());
    int keep = 12;
    for (int i = 1; i < n; i++) {
      keep = min(keep, x.at(i) - x.at(i - 1));
    }
    keep = min({keep, x.front(), 24 - x.back()});
    ans = max(ans, keep);
  }
  
  cout << ans << '\n';
}