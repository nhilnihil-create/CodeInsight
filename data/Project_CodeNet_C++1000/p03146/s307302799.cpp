#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int s;
  cin >> s;
  map<int, int> mp;
  int ans = 0;
  mp[s]++;
  for (int i = 1; i < 1000001; i++) {
    if (s % 2 == 0) {
      s /= 2;
      mp[s]++;
      if (mp[s] == 2) {
        ans = i + 1;
        break;
      }
    } else {
      s = 3 * s + 1;
      mp[s]++;
      if (mp[s] == 2) {
        ans = i + 1;
        break;
      }
    }
  }
  cout << ans;

  return 0;
}
