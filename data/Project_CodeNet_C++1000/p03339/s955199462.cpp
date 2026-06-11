#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  string s;
  cin >> n >> s;
  vector<ll> from_left(n+1, 0);
  vector<ll> from_right(n+1, 0);
  rep(i, n) {
    from_left[i+1] = from_left[i];
    if (s[i] == 'W') from_left[i+1]++;
  }
  repr(i, n-1) {
    from_right[i] = from_right[i+1];
    if (s[i] == 'E') from_right[i]++;
  }
  ll ans = INF;
  for(int i = 0; i <= n; i++) {
    ans = min(ans, from_left[i] + from_right[i]);
  }
  cout << ans << endl;

  
  return 0;
}