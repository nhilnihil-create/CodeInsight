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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}