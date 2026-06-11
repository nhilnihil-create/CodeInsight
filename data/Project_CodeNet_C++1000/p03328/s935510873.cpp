#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  ll a, b;
  cin >> a >> b;

  ll c = b - a;

  ll B = 0;
  ll old = 0;
  for (int i = 1; i <= c; ++i) {
    B = old + i;
    old = B;
  }

  cout << B - b << endl;
  
  return 0;
}