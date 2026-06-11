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
  vector<ll> a(n), sum(n + 1, 0);
  map<ll, ll> mp;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
    mp[sum[i]]++;
  }
  mp[sum[n]]++;
  ll ans = 0;
  for(auto p : mp) {
    ans += p.second * (p.second - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}