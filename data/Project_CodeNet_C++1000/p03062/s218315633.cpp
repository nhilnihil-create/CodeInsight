#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define MOD 1000000007

int main()
{
  int n;
  ll tmp;
  ll min = pow(10, 9);
  ll ans = 0;
  int nega = 1;
  cin >> n;
  rep(i, n) {
    cin >> tmp;
    ans += abs(tmp);
    if (tmp < 0) nega *= -1;
    if (abs(tmp) < min) min = abs(tmp);
  }
  if (nega < 0) ans -= 2 * min;
  cout << ans << endl;

  return 0;
}
