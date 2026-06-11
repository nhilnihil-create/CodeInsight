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

int f(int x) {
  return x % 2 == 0 ? x / 2 : 3 * x + 1;
}

int main(void) {
  int s;
  cin >> s;
  map<int, int> mp;
  int ans;
  mp[s]++;
  for (int i = 2; ; i++) {
    s = f(s);
    if (mp.count(s) > 0) {
      ans = i;
      break;
    }
    mp[s]++;
  }
  cout << ans << endl;
  return 0;
}
