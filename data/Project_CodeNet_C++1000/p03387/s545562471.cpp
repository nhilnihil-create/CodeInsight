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
  ll A, B, C;
  cin >> A >> B >> C;
  ll M = max({A, B, C});
  if ((3 * M) % 2 == (A + B + C) % 2) {
    cout << ((3 * M - (A + B + C)) / 2) << endl;
  } else {
    cout << ((3 * (M + 1) - (A + B + C)) / 2) << endl;
  }
  return 0;
}