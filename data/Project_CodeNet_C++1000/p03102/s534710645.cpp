#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> bi(m);
  for (int i = 0; i < m; i++) cin >> bi.at(i);
  vector<int> ai(m);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ai.at(j);
    }
    int sum = 0;
    for (int j = 0; j < m; j++) {
      sum += bi.at(j)*ai.at(j);
    }
    if (sum+c > 0) ans++;
  }
  cout << ans << endl;
}