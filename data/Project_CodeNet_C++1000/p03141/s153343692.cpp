#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(3));
  for(int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = a[i][0] + a[i][1];
  }
  sort(a.begin(), a.end(),
      [](const vector<ll> &l, const vector<ll> &r) { return l[2] > r[2]; });
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      ans += a[i][0];
    } else {
      ans -= a[i][1];
    }
  }
  cout << ans << endl;
  return 0;
}