#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  if (n == 1 || m == 1) {
    ans = max((ll)1, n-2) * max((ll)1, m-2);
  } else {
    ans = (n-2)*(m-2);
  }
  
  cout << ans << endl;
  
  return 0;
}