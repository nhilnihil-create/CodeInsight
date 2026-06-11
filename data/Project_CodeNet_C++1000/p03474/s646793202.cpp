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
  int A, B;
  string S;
  cin >> A >> B >> S;

  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '-') {
      if (i != A) {
        cout << "No" << endl;
        return;
      }
    } else if (i == A) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;

}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
