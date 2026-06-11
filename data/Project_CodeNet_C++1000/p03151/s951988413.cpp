#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> a, b, v;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for (auto& p : a) cin >> p;
  b.resize(n);
  for (auto& p : b) cin >> p;
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 0, cnt = 0;
  for (int i = 0; i < n; ++i)
    if (a[i] > b[i])
      v.push_back(a[i] - b[i]);
    else if (a[i] < b[i]) {
      cnt += b[i] - a[i];
      ++res;
    }
  sort(v.begin(), v.end(), greater<long long>());
  for (auto p : v)
    if (cnt) {
      cnt -= min(cnt, p);
      ++res;
    }
  if (cnt > 0) return -1;
  return res;
}