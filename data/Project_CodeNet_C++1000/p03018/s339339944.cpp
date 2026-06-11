#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll INF = 1LL<<60;

int main()
{
  string s; cin>>s;
  string t = "";
  ll n = s.size();
  rep(i, n) {
    if (i < n-1) {
      if (s[i] == 'B' && s[i+1] == 'C') {
        t.push_back('D');
        i++;
        continue;
      }
    }
    t.push_back(s[i]);
  }

  ll a = 0;
  ll ans = 0;
  for (auto c:t) {
    if (c == 'A') a++;
    else if (c == 'D') ans += a;
    else a = 0;
  }
  cout << ans << endl;

  return 0;
}
