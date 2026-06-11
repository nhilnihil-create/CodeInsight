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
  ll N;
  cin >> N;
  vector<string> x(N), u(N);
  long double ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> u[i];
    if (u[i] == "BTC") {
      ans += 380000 * stod(x[i]);
    } else {
      ans += stoll(x[i]);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}