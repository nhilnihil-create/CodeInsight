#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int d, n;
  cin >> d >> n;

  if (n == 100) {
    ll ans = pow(100, d) * n + pow(100, d);
    cout << ans << endl;
  } else {
    ll ans = pow(100, d) * n;
    cout << ans << endl;
  }
  return 0;
}