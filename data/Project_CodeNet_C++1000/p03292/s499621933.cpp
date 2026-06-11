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
  ll A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  ll ans = min({abs(A1 - A2) + abs(A2 - A3), abs(A1 - A3) + abs(A2 - A3),
                abs(A1 - A3) + abs(A2 - A1)});
  cout << ans << endl;
  return 0;
}