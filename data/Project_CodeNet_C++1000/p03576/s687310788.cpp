#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<long long> x(N), y(N);
  for (int i = 0; i < N; i++) cin >> x.at(i) >> y.at(i);
  long long ans = 1LL << 62;
  for (int left = 0; left < N; left++) {
    for (int right = 0; right < N; right++) {
      if (left == right) continue;
      if (x.at(left) > x.at(right)) continue;
      for (int up = 0; up < N; up++) {
        for (int down = 0; down < N; down++) {
          if (up == down) continue;
          if (y.at(down) > y.at(up)) continue;
          int cnt = 0;
          for (int i = 0; i < N; i++) {
            if (x.at(i) < x.at(left)) continue;
            if (x.at(i) > x.at(right)) continue;
            if (y.at(i) > y.at(up)) continue;
            if (y.at(i) < y.at(down)) continue;
            cnt++;
          }
          if (cnt >= K) {
            long long width = x.at(right) - x.at(left);
            long long height = y.at(up) - y.at(down);
            ans = min(ans, width * height);
          }
        }
      }
    }
  }
  cout << ans << endl;
}