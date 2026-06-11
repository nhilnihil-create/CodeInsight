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
  int N;
  string S;
  cin >> N >> S;

  vector<int> v(26), z(26);
  for (char c:S) {
    z[c-'a']++;
  }

  int ans = 0;
  for (int p = 0; p < S.size() - 1; p++) {
    char c = S[p];
    v[c-'a']++;
    z[c-'a']--;

    int a = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] > 0 && z[i] > 0) {
        a++;
      }
    }
    ans = max(ans, a);
  }
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
