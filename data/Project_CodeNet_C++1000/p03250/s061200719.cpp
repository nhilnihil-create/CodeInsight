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
  ll a, b, c;
  cin >> a >> b >> c;
  ll mid = a + b + c - max({a, b, c}) - min({a, b, c});
  ll ans = 10 * max({a, b, c}) + mid + min({a, b, c});
  cout << ans << endl;
  return 0;
}