#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = 0;
  if (a % 2 == 1) ans ^= a++;
  if (b % 2 == 0) ans ^= b--;
  if ((b - a + 1) / 2 % 2 == 1) ans ^= 1;
  cout << ans << endl;
  return 0;
}