#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> x(m);
  for (int i = 0; i < m; i++) cin >> x[i];
  sort(x.begin(), x.end());

  multiset<int> space;
  for (int i = 0; i < m - 1; i++) {
    int s = x[i + 1] - x[i] - 1;
    if (s > 0) space.insert(s);
  }

  int ans = x[m - 1] - x[0] + 1 - n;
  if (space.size() == 0) {
    cout << max(0, ans) << endl;
    return 0;
  }

  auto itr = space.rbegin();
  for (int i = 0; i < n - 1 && itr != space.rend(); i++) {
    ans -= *itr;
    itr++;
  }
  ans = max(0, ans);
  cout << ans << endl;
}
