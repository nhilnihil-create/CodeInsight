#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> l(m);
  vector<int> r(m);

  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
  }
  int max_l = 1;
  int min_r = n;
  for (int i = 0; i < m; i++) {
    max_l = max(max_l, l[i]);
    min_r = min(min_r, r[i]);
  }

  int ans = min_r - max_l + 1;
  ans = max(ans, 0);

  cout << ans << endl;
  return 0;
}