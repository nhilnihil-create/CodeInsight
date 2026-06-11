#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  int N, Y;
  cin >> N >> Y;
  for (int i = 0; i <= N; i++) {
    for (int p = 0; p <= N-i; p++) {
      int z = N-i-p;
      if (10000*i + 5000*p + 1000*z == Y) {
        printf("%lld %lld %lld\n", i, p, z);
        return;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
