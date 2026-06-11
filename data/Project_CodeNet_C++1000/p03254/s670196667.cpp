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
  int N, x;
  cin >> N >> x;
  vector<int> A(N);

  for (int &a: A) {
    cin >> a;
  }

  sort(A.begin(), A.end());

  int ans = 0;
  for (int a: A) {
    if (a <= x) {
      x-=a;
      ans++;
    }
  }
  if (N == ans && x > 0) {
    ans--;
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
