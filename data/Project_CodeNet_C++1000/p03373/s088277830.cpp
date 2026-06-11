#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  ll A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
  
  ll ans = 0;
  if (A + B <= 2*C) ans = A * X + B * Y;
  else if (X >= Y) {
    if (A >= 2*C) ans = 2 * C * X;
    else ans = 2 * C * Y + A * (X-Y);
  } else {
    if (B >= 2*C) ans = 2 * C * Y;
    else ans = 2 * C * X + B * (Y-X);
  }
  
  cout << ans << endl;
  
}