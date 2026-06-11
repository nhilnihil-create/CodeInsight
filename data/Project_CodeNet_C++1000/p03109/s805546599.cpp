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
  string s;
  cin >> s;
  ll y = stoll(s.substr(0, 4));
  ll m = stoll(s.substr(5, 2));
  if ((y == 2019 && m <= 4) || (y < 2019)) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
  return 0;
}
