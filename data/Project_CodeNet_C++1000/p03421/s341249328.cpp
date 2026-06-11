#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, a, b;
  cin >> n >> a >> b;
  
  if (a * b < n || n + 1 < a + b) {
    cout << -1 << '\n';
    return 0;
  }
  
  int res = n;
  vector<int> x(a);
  x.at(0) = b;
  for (int i = 1; i < a; i++) x.at(i) = 1;
  res -= b + (a - 1);
  
  for (int i = 1; i < a; i++) {
    if (res == 0) break;
    if (res < b) {
      x.at(i) += res;
      res = 0;
    }
    else {
      x.at(i) += b - 1;
      res -= b - 1;
    }
  }
  
  int now = 1;
  for (int i = 0; i < a; i++) {
    now += x.at(i);
    for (int j = 0; j < x.at(i); j++) {
      now--;
      if (i || j) cout << " ";
      cout << now;
    }
    now += x.at(i);
  }
  cout << '\n';
}