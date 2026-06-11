#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
  ll n;
  string s;
  
  ll b=0, w =0;
  cin >> n >> s;
  
  for (int i=0; i<n; i++) {
    if (s[i] == '#')
      b++;
    else
      w++;
  }
  ll ans = min(b,w);
  ll lb=0, lw=0;
  
  for (int i=0; i<n; i++) {
    if (s[i] == '#')
    {
      lb++;
      b--;
    }
    else {
      lw++;
      w--;
    }
    ans = min(lb+w, ans);
  }
  cout << ans << endl;
  return 0;
}
  