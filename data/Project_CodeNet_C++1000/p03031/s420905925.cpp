#include <cmath>
#include <iostream>
using namespace std;
typedef long long Int;

Int n, m, k[20], s[20][20], p[20];

int main() {
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cin >> k[j];
    for (int k_ = 0; k_ < k[j]; k_++) cin >> s[j][k_];
  }
  for (int j = 0; j < m; j++) cin >> p[j];

  Int ans = 0;
  for (int bit = 0; bit < pow(2, n); bit++) {
    Int switches[n];
    for (int i = 0; i < n; i++) {
      switches[i] = 0;
      if (bit >> i & 1) {
        switches[i] = 1;
      }
    }

    int light_cnt = 0;
    for (int j = 0; j < m; j++) {
      int on_cnt = 0;
      for (int k_ = 0; k_ < k[j]; k_++) {
        if (switches[s[j][k_] - 1]) {
          on_cnt++;
        }
      }
      if (on_cnt % 2 == p[j]) {
        light_cnt++;
      }
    }
    if (light_cnt == m) {
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}