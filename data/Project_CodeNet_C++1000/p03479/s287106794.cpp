#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
using ll = long long;
const int INF = 1e8;

int main() {
  ll X, Y;
  cin >> X >> Y;
  ll ans = 1;
  ll A = X;
  while (1) {
    A = A * 2;
    if (A > Y) {
      break;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
