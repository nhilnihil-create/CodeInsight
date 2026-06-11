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

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> diff(n);
  for (int i = 0; i < n; i++) {
    diff[i] = abs(x - a[i]);
  }

  int ans = diff[0];
  for (int i = 0; i < n; i++) {
    ans = gcd(diff[i], ans);
  }

  cout << ans << endl;

  return 0;
}