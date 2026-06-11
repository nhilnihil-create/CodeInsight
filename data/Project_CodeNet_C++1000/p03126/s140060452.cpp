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

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<int> v(m, 0);
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int a;
      cin >> a;
      --a;
      v[a]++;
    }
  }
  int cnt = 0;
  rep(i, v.size()) {
    if (v[i] == n) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
