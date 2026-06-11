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
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll x = x2 - x1;
  ll y = y2 - y1;
  cout << x2 - y << " " << y2 + x << " " << x1 - y << " " << y1 + x << endl;
  return 0;
}