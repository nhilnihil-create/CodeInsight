#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;

  ll mx = 0;
  mx = min({a, b, c, d, e});

  ll ans = n/mx;
  if(n%mx != 0) ++ans;
  ans += 4;
  cout << ans << endl;

  return 0;
}
