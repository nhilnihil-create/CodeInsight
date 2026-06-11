#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n; cin>>n;
  ll t; cin>>t; //基準
  ll a; cin>>a; //平均気温

  double min=pow(10,6);
  ll ans;

  rep(i,n) {
    ll tmp; cin>>tmp;
    // cout << abs(a - (t - tmp * 0.006)) << endl;
    // if (min > abs(a - (t - tmp * 0.006))) ans = i+1;
    if (min > abs(a - (t - tmp * 0.006))) {
      // cout << "min: " << min << "abs" << abs(a - (t - tmp * 0.006)) << endl;
      // cout << "debug: "<< i <<endl;
      // cout << "debug: "<< abs(a - (t - tmp * 0.006)) << endl;
      min = abs(a - (t - tmp * 0.006));
      ans = i+1;
    }
  }

  cout << ans << endl;
  return 0;
}