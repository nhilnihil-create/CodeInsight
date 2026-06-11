#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main () {
  vector<int> cost(3);
  for (int i = 0; i < 3; ++i) {
    cin >> cost.at(i);
  }
  sort(cost.begin(), cost.end());
  int ans = 0;
  ans += cost.at(1) - cost.at(0);
  ans += cost.at(2) - cost.at(1);
  cout << ans << endl;
}