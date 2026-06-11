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
  string s = "MARCH";
  int c[5] = {0};
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    for (int j = 0; j < 5; j++) {
      if (t[0] == s[j]) {
        c[j]++;
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      for (int k = j + 1; k < 5; k++) {
        ans += ll(c[i]) * ll(c[j]) * ll(c[k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}