#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int, int>> red(N), blue(N);
  vector<bool> used(N, false);
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    red[i] = {b, a};
  }  
  for (int i = 0; i < N; i++) {
    int c, d; cin >> c >> d;
    blue[i] = {c, d};
  }
  sort(red.begin(), red.end());
  sort(blue.begin(), blue.end());

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int b_x = blue[i].first, b_y = blue[i].second;
    for (int j = N - 1; j >= 0; j--) {
      int r_x = red[j].second, r_y = red[j].first;
      if (used[j]) continue;
      if (r_x >= b_x) continue;
      if (r_y < b_y) {
        ans++;
        used[j] = true;
        break;
      }
    }
  }
  cout << ans << endl;
}