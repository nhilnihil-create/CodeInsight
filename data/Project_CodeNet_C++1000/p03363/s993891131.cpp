#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;
map<long long, long long> mp;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  mp[0] = 1;
  long long res = 0, now = 0;
  for (int i = 0; i < n; ++i) {
    now += a[i];
    res += mp[now];
    ++mp[now];
  }
  return res;
}
