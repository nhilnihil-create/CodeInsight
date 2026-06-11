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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ll> s(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    s[i + 1] = s[i] + a[i];
  }
  map<ll, ll> mp;
  for (int i = 0; i <= n; ++i) {
    mp[s[i] % m]++;
  }
  ll ans = 0;
  for (auto a : mp) {
    ans += a.second * (a.second - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}