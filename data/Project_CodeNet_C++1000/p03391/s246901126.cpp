#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  bool same = true;
  ll sum = 0, keep = 1e9;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    if (a != b) same = false;
    sum += a;
    if (a > b) keep = min(keep, b);
  }
  
  if (same) cout << "0\n";
  else cout << sum - keep << '\n';
}