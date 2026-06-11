#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); i++)
typedef long long ll;

int main()
{
  string s; cin >> s;
  int n = s.size();
  bool f = false;
  for (int i=1; i<n; i++) {
    if (s[i] !='9') f = true;
  }
  ll ans = (s[0]-'0') + (n-1)*9;
  //cout << n << " " << ans << " ";
  if (f) ans--;
  cout << ans << endl;

  return 0;
}
