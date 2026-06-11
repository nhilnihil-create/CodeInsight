#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> V(3);
  for (int i = 0; i < 3; i++) cin >> V.at(i);
  sort(V.rbegin(), V.rend());
  if (V.at(0) == V.at(1) && V.at(1) == V.at(2)) return cout << 0 << "\n", 0;
  int ans = 0;
  int tmp = V.at(0) - V.at(1);
  ans += tmp;
  V.at(2) += tmp;
  tmp = V.at(0) - V.at(2);
  if (tmp % 2 == 0) cout << ans + tmp / 2 << "\n";
  else cout << ans + tmp / 2 + 2 << "\n";
}