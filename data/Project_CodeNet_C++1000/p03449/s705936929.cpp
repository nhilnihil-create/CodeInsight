#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int a[2][n];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  // 全探索
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    // i 番目で下移動
    for (int j1 = 0; j1 <= i; j1++) {
      sum += a[0][j1];
    }
    for (int j2 = i; j2 < n; j2++) {
      sum += a[1][j2];
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
}
