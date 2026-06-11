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
  if (a + b >= c) {
    cout << b + c << endl;
  } else {
    cout << b + (a + b + 1) << endl;
  }
  return 0;
}