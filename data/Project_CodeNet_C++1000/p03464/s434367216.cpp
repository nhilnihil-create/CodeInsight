#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &e: a) cin >> e;
  reverse(a.begin(), a.end());
  
  ll l=2, r=2;
  for (auto e: a) {
    if (r < e) {
      cout << -1 << endl;
      return 0;
    }
    ll ming = (l+e-1)/e;
    ll maxg = r/e;
    if (maxg < ming) {
      cout << -1 << endl;
      return 0;
    }
    l = ming * e;
    r = maxg * e + e - 1;
  }
  
  cout << l << " " << r << endl;
  
  return 0;
}
  