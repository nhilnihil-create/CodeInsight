#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ": " << x << endl

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  multiset<int> ms;
  int res = numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    if (i >= k) 
      ms.erase(ms.lower_bound(a[i - k]));
    ms.insert(a[i]);
    if (i >= k - 1) {
      int mn = 0;
      int mx = 0;
      mn = min(mn, *ms.begin()), mx = max(mx, *ms.rbegin());
      res = min(res, min({2 * abs(mn) + abs(mx), abs(mn) + 2 * abs(mx)}));
    }
  }
  cout << res << '\n';
  return 0;
}