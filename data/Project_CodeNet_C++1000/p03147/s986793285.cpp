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
  int n;
  cin >> n;
  vector<int> h(n);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  int ans = 0;
  int active = 0;
  for (int i = 0; i < n; i++) {
    if (active >= h[i]) {
      active = h[i];
    } else {
      ans += h[i] - active;
      active = h[i];
    }
  }
  cout << ans << endl;
  return 0;
}