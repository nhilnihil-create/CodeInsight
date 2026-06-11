#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  vector<int> v(3);
  int K, ans = 0, ma = 0;
  rep(i, 0, 3) {
    cin >> v[i];
    ans += v[i];
    ma = max(ma, v[i]);
  }
  cin >> K;

  int x = ma;
  rep(i, 0, K) x *= 2;
  ans += x - ma;

  cout << ans << endl;

  return 0;
}
