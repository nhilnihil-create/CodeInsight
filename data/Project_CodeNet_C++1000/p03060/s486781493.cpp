#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> V(n), C(n);
  for (int i = 0; i < n; i++) cin >> V[i];
  for (int i = 0; i < n; i++) cin >> C[i];

  int ans = - 1e9;
  for (int i = 0; i < (1 << n); i++) {
    int x = 0, y = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        x += V[j];
        y += C[j];
      }
    }
    ans = max(ans, x - y);
  }

  cout << ans << endl;
  return 0;
}