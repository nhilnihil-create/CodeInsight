#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> count(m);
  for (int i = 0; i < n; i++) {
    int k; cin >> k;
    vector<int> ai(k);
    for (int j = 0; j < k; j++) cin >> ai.at(j);
    for (int a : ai) count.at(a-1) += 1;
  }
  int ans = 0;
  for (int c : count) if (c == n) ans++;
  cout << ans << endl;
}
