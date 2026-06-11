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
  string a, b, c;
  cin >> a >> b >> c;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] == b[i] && c[i] == b[i]) continue;
    if (a[i] == b[i] || c[i] == b[i] || a[i] == c[i]) {
      ans++;
    } else {
      ans += 2;
    }
  }
  cout << ans << endl;
  return 0;
}