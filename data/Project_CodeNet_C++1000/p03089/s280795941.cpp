#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  vector<int> b(n), ans;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int j = 0; j < n; j++) {
    for (int i = b.size() - 1; i >= 0; i--) {
      if (b[i] == i + 1) {
        ans.push_back(b[i]);
        b.erase(b.begin() + i);
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  if (ans.size() != n) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl;
    }
  }
  return 0;
}