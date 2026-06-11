#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n, q;
  cin >> n >> q;
  
  string s;
  cin >> s;
  
  vector<char> t(q), d(q);
  for (int i = 0; i < q; i++){
    cin >> t[i] >> d[i];
  }

  ll ans = n;
  ll l, r, m;
  l = -1, r = n;
  while (l + 1 < r){
    m = (l + r) / 2;
    ll cur = m;
    for (int i = 0; i < q; i++){
      if (s[cur] == t[i]){
        cur += (d[i] == 'R' ? 1 : -1);
      }
      if (cur == n)
        break;
      if (cur == -1)
        break;
    }
    if (cur == n)
      r = m;
    else
      l = m;
  }
  ans -= n - r;
  
  l = -1, r = n;
  while (l + 1 < r){
    m = (l + r) / 2;
    ll cur = m;
    for (int i = 0; i < q; i++){
      if (s[cur] == t[i]){
        cur += (d[i] == 'R' ? 1 : -1);
      }
      if (cur == n)
        break;
      if (cur == -1)
        break;
    }
    if (cur == -1)
      l = m;
    else
      r = m;
  }
  ans -= l + 1;

  cout << ans << endl;
 
  return 0;
}
