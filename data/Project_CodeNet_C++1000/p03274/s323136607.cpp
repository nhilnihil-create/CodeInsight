#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int64_t> x(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i);
  }
  int64_t ans = 100000000000000;
  for (int i = 0; i < N - K + 1; i++) {
    int64_t l = x.at(i);
    int64_t r = x.at(i + K - 1);
    if (r < 0) {
      ans = min(ans, abs(l));
    }
    else if (l < 0) {
      ans = min(ans, abs(min(abs(l), r) * 2) + max(abs(l), r));
    }
    else {
      ans = min(ans, r);
    }
  }
  cout << ans << endl;
}