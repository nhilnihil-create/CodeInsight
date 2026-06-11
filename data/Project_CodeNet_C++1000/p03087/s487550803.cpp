#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;

int f(int x) {
  return x % 2 == 0 ? x / 2 : 3 * x + 1;
}

int main(void) {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<P> qs(q);
  rep(i, q) {
    cin >> qs[i].first >> qs[i].second;
  }

  vector<int> vec(n);
  int cnt = 0;
  vec[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    string ss = s.substr(i, 2);
    if (ss == "AC") cnt++;
    vec[i + 1] = cnt;
  }

  rep(i, q) {
    int l = qs[i].first;
    int r = qs[i].second;
    --l;
    --r;
    int ans = vec[r] - vec[l];
    cout << ans << endl;
  }

  return 0;
}
