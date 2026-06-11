#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
  ll a, b, c;
  cin >> a >> b >> c;

  ll mx = max({a, b, c});
  ll mn = min({a, b, c});
  ll md = a + b + c - mx - mn;

  ll ans = 0;
  ans += mx - md;
  if((md - mn) % 2 == 0) ans += (md - mn)/2;
  else ans += (md - mn + 1)/2/*mn +2*/ + 1;//mxとmd ++

  cout << ans << endl;
  return 0;
}
