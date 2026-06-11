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
  ll s;
  cin >> s;
  ll a = s;
  set<ll> searched;
  searched.insert(s);
  ll ans = INF;
  int i = 2;
  while (i < 1000005) {
    if (a % 2 == 0) {
      a = a / 2;
    } else {
      a = 3 * a + 1;
    }
    if (searched.find(a) != searched.end()) {
      ans = i;
      break;
    }
    i++;
    searched.insert(a);
  }
  cout << ans << endl;
  return 0;
}