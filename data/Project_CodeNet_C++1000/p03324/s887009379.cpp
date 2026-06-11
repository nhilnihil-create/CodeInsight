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
  ll D, N;
  cin >> D >> N;
  ll base = pow(100, D);
  ll ans = base * (N + N / 100);
  cout << ans << endl;
  return 0;
}