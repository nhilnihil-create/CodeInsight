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
  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  ll x, y, max_x = X, min_y = Y;
  for (int i = 0; i < N; i++) {
    cin >> x;
    max_x = max(max_x, x);
  }
  for (int i = 0; i < M; i++) {
    cin >> y;
    min_y = min(min_y, y);
  }
  if (max_x < min_y) {
    cout << "No War" << endl;
  } else {
    cout << "War" << endl;
  }
  return 0;
}