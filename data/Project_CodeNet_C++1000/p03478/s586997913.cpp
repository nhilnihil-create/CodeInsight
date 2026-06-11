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

void solve();

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

void solve() {
  int N, A, B; cin >> N >> A >> B;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int x = i;
    int p = 0;
    while(x) {
      p += x%10;
      x/=10;
    }

    if (A <= p && p <= B) {
      ans+=i;
    }
  }

  cout << ans << endl;
}
