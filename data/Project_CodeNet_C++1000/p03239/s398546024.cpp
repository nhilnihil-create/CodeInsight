#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, t;
  cin >> n >> t;
  int res = numeric_limits<int>::max();
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (b <= t)
      res = min(res, a);
  }
  if (res == numeric_limits<int>::max())
    cout << "TLE";
  else
    cout << res;
  return 0; 
}