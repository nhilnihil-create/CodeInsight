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
  ll X;
  cin >> X;
  ll ans = 1;
  for (ll i = 2; i * i <= X; i++) {
    ll c = i;
    while (c * i <= X) {
      c *= i;
    }
    ans = max(ans, c);
  }
  cout << ans << endl;
  return 0;
}