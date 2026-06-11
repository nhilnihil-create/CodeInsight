#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
  int n, m;
  cin >> n >> m;
  vector<int> x(m);
  rep(i, m) cin >> x[i];
  sort(x.begin(), x.end());

  vector<int> d(m - 1);
  rep(i, m - 1) d[i] = abs(x[i] - x[i + 1]);
  sort(d.begin(), d.end(), greater<int>());

  int ans = 0;
  for (int i = n - 1; i < m - 1; i++) ans += d[i];

  cout << ans << endl;

}
  
