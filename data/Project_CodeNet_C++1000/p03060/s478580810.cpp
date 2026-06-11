#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  int N;
  cin >> N;
  int ans = 0;
  vector<vector<int>> houseki(2, vector<int>(N));
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < N; i++) {
      int p;
      cin >> p;
      houseki[j][i] = p;
    }
  }
  for (int i = 0; i < N; i++) {
    if (houseki[0][i] - houseki[1][i] > 0) {
      ans += houseki[0][i] - houseki[1][i];
    }
  }
  cout << ans << endl;
}