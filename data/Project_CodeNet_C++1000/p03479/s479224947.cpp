#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll x, y;
  cin >> x >> y;
  ll count = 0;
  for (ll i = x; i <= y; i = i * 2) {
    count++;
  }
  cout << count << endl;
  return 0;
}