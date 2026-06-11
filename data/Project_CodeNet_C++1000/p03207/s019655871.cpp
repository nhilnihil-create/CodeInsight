#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
  }
  sort(p.begin(), p.end(), greater<int>());
  int ans = p[0] / 2 + accumulate(p.begin() + 1, p.end(), 0);
  cout << ans << endl;
  return 0;
}