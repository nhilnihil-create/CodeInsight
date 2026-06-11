#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i);
  }
  vector<int> cost(n, 0);
  for (int i = 0; i < m; i++) {
    cost.at(a.at(i))++;
  }
  int left = 0;
  int right = 0;
  for (int i = 1; i < x; i++) {
    left += cost.at(i);
  }
  for (int i = x; i < n; i++) {
    right += cost.at(i);
  }
  cout << min(left, right) << endl;
  return 0;
}
