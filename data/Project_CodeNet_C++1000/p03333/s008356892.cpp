#include <bits/stdc++.h>
using namespace std;
int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n + 1), y(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  sort(x.rbegin(), x.rend());
  sort(y.begin(), y.end());
  long long ans = 0;
  for (int i = 0; i < n + 1; i++) {
    if (x[i] > y[i]) {
      ans += 2 * (x[i] - y[i]);
    }
  }
  cout << ans << '\n';
  return 0;
}