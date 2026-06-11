#include <bits/stdc++.h>
using namespace std;

int n, C;
int imos[30][100002];

int main() {
  cin >> n >> C;
  for (int i = 0; i < n; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    imos[c - 1][s]++;
    imos[c - 1][t + 1]--;
  }

  for (int i = 0; i < C; i++) {
    for (int j = 0; j < 100000; j++) {
      imos[i][j + 1] += imos[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i <= 100000; i++) {
    int cnt = 0;
    for (int j = 0; j < C; j++) {
      if (imos[j][i] > 0) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}
