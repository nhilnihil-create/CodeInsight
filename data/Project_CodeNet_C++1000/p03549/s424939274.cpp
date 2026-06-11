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
  ll N, M;
  cin >> N >> M;
  ll ans = pow(2, M) * (1900 * M + 100 * (N - M));
  cout << ans << endl;
  return 0;
}