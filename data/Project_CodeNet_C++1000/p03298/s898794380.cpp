#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  int n; cin>>n;
  string s; cin>>s;
  string sl = s.substr(0, n);
  string sr = s.substr(n);
  map<pair<string, string>, ll> mpl;
  map<pair<string, string>, ll> mpr;
  {
    for (int bits=0; bits<1<<n; bits++) {
      string s1 = "";
      string s2 = "";
      for (int i=0; i<n; i++) {
        if (bits>>i&1) s2.push_back(sl[i]);
        else s1.push_back(sl[i]);
      }
      reverse(s2.begin(), s2.end());
      mpl[make_pair(s1, s2)]++;
    }
  }
  {
    for (int bits=0; bits<1<<n; bits++) {
      string s1 = "";
      string s2 = "";
      for (int i=0; i<n; i++) {
        if (bits>>i&1) s2.push_back(sr[i]);
        else s1.push_back(sr[i]);
      }
      reverse(s2.begin(), s2.end());
      mpr[make_pair(s2, s1)]++;
    }
  }
  ll ans = 0;
  for (auto v:mpl) {
    ans += v.second * mpr[v.first];
  }
  cout << ans << endl;

  return 0;
}
