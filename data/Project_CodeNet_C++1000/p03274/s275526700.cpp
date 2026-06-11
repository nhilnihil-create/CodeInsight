#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K, y, ans{1 << 30};
  cin >> N >> K;
  if (!--K) {
    while (cin >> y) ans = min(ans, abs(y));
  } else {
    vector<int> x(K, 1 << 30);
    for (; N; --N) {
      cin >> y;
      auto a = x[N % K];
      if (a < 0 && y > 0)
        ans = min(ans, y - a + min(-a, y));
      else
        ans = min(ans, max(abs(a), abs(y)));
      x[N % K] = y;
    }
  }
  cout << ans << endl;
}
