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
  string S;
  cin >> S;
  ll ans = INF;
  for (int i = 0; i + 2 < S.size(); i++) {
    string X = S.substr(i, 3);
    ans = min(ans, abs(stoll(X) - 753LL));
  }
  cout << ans << endl;
  return 0;
}