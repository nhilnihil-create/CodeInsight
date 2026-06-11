#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v[202020];

signed main() {
  int H, W, N;
  cin >> H >> W >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    v[y].push_back(x);
  }

  int ans = H, cnt = 0;
  for (int i = 1; i <= W; i++) {
    sort(v[i].begin(), v[i].end());
    for (auto h : v[i]) {
      if (h - cnt == i) cnt++;
      if (h - cnt > i) ans = min(ans, h - 1);
    }
  }

  cout << ans << endl;
  return 0;
}
