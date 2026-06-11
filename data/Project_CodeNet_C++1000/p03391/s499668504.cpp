#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<ll> a(n), b(n);
  ll sum = 0, keep = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a.at(i) >> b.at(i);
    sum += a.at(i);
    if (a.at(i) > b.at(i)) keep = min(keep, b.at(i));
  }
  
  if (a == b) cout << 0 << '\n';
  else cout << sum - keep << '\n';
}