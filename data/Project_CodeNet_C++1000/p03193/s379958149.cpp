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
  ll N, H, W;
  cin >> N >> H >> W;
  ll ans = 0, a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    if (H <= a && W <= b) ans++;
  }
  cout << ans << endl;
  return 0;
}