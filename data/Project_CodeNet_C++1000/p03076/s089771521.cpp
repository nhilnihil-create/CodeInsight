#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int x = (a-1) % 10;
  x = min(x,(b-1) % 10);
  x = min(x,(c-1) % 10);
  x = min(x,(d-1) % 10);
  x = min(x,(e-1) % 10);
  int ans = 0;
  ans += ((a+9) / 10) * 10;
  ans += ((b+9) / 10) * 10;
  ans += ((c+9) / 10) * 10;
  ans += ((d+9) / 10) * 10;
  ans += ((e+9) / 10) * 10;
  cout << ans-9+x;
    
  return 0;
}



