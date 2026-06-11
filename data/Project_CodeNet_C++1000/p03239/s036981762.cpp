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
  ll N, T;
  cin >> N >> T;
  ll c, t, min_c = INF;
  for (int i = 0; i < N; i++) {
    cin >> c >> t;
    if (t <= T && c < min_c) {
      min_c = c;
    }
  }
  if (min_c == INF) {
    cout << "TLE" << endl;
  } else {
    cout << min_c << endl;
  }
  return 0;
}