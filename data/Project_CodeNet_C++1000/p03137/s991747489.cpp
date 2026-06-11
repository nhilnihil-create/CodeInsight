#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (n >= m) { cout << 0 << endl; return 0; }

  vector<int> x(m);
  rep(i,m) cin >> x[i];
  sort(x.begin(), x.end());

  int res = x[m-1] - x[0];
  vector<int> diff(m-1);
  rep(i,m-1) diff[i] = x[i+1] - x[i];
  sort(diff.rbegin(), diff.rend());
  rep(i,n-1) res -= diff[i];

  cout << res << endl;
  return 0;
}