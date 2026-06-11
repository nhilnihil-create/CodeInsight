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

  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i] - 1;
  }

  cout << ans << endl;
  return 0;
}