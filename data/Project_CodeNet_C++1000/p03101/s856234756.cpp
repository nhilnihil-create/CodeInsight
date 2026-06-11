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
  ll H, W, h, w;
  cin >> H >> W >> h >> w;
  ll ans = (H - h) * (W - w);
  cout << ans << endl;
  return 0;
}