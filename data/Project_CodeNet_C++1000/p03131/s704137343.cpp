#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll k, a, b;
  cin >> k >> a >> b;
  
  ll now = 1;
  if (b - a > 2) {
    if (now + k >= a) {
      now += a - 1;
      k -= a - 1;
      now += (b - a) * (k / 2);
      k %= 2;
      if (k == 1) now++;
    }
    else {
      now += k;
    }
  }
  else {
    now += k;
  }
  
  cout << now << '\n';
}