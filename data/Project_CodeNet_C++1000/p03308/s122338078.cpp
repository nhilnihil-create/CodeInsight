#include <algorithm>
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
  int N;
  cin >> N;
  int ma = 0, mi = INF, a;
  rep(i, 0, N) {
    cin >> a;
    ma = max(ma, a);
    mi = min(mi, a);
  }

  cout << abs(ma - mi) << endl;

  return 0;
}
