#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<long long> x(N), y(N);
  for (int i = 0; i < N; i++) cin >> x.at(i) >> y.at(i);
  long long ans = 1LL << 62;
  for (int i = 0; i < N; i++) {  // 左端
    for (int j = 0; j < N; j++) {  // 右端
      if (!(x.at(i) <= x.at(j))) continue;
      for (int s = 0; s < N; s++) {  // 上端
        for (int t = 0; t < N; t++) {  // 下端
          if (!(y.at(t) <= y.at(s))) continue;
          int cnt = 0;
          for (int k = 0; k < N; k++) {
            if (!(x.at(i) <= x.at(k))) continue;
            if (!(x.at(k) <= x.at(j))) continue;
            if (!(y.at(k) <= y.at(s))) continue;
            if (!(y.at(t) <= y.at(k))) continue;
            cnt++;
          }
          if (cnt >= K) {
            ans = min(ans, (x.at(j) - x.at(i)) * (y.at(s) - y.at(t)));
          }
        }
      }
    }
  }
  cout << ans << endl;
}