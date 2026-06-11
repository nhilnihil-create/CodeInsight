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
  ll X, Y;
  cin >> X >> Y;
  if (X % Y == 0) {
    cout << -1 << endl;
  } else {
    cout << X << endl;
  }
  return 0;
}