#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, x; cin >> n >> x;
  // vector<ll> donuts;
  ll min_donut = pow(10, 6);
  int ans = 0;

  rep(i,n) {
    ll tmp; cin >> tmp;
    x -= tmp;
    ans ++;

    if (min_donut > tmp) {
      min_donut = tmp;
    }
  }
  ans = ans + (x / min_donut);
  cout << ans << endl;

  return 0;
}