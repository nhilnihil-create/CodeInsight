#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000009;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> f(n, vector<int>(10, 0));
  vector<vector<int>> p(n, vector<int>(11, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> f[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 10; j++) {
      cin >> p[i][j];
    }
  }

  int ans = -INF;
  for (int bit = 1; bit < (1 << 10); bit++) {
    int prof = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < 10; j++) {
        if (f[i][j] == 1 && f[i][j] == ((bit >> j) & 1)) {
          cnt++;
        }
      }
      prof += p[i][cnt];
    }
    ans = max(ans, prof);
  }
  cout << ans << endl;

  return 0;
}