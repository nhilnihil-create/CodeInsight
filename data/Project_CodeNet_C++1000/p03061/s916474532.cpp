#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> l(n + 2), r(n + 2);
  l[0] = 0, r[n + 1] = 0;
  for (int i = 1; i < n; ++i) {
    l[i] = gcd(l[i - 1], a[i - 1]);
  }
  for (int i = n; i >= 2; --i) {
    r[i] = gcd(r[i + 1], a[i - 1]);
  }
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, gcd(l[i - 1], r[i + 1]));
  }
  cout << ans << endl;
  return 0;
}