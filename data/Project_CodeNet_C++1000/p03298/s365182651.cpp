#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  string s;
  cin >> n >> s;
  
  string t1 = s.substr(0, n), t2 = s.substr(n);
  reverse(t2.begin(), t2.end());
  
  map<pair<string, string>, ll> mp;
  for(int bit = 0; bit < (1 << n); bit++){
    string keep1, keep2;
    for(int i = 0; i < n; i++){
      if(bit & (1 << i)) keep1 = keep1 + t1.at(i);
      else keep2 = keep2 + t1.at(i);
    }
    mp[make_pair(keep1, keep2)]++;
  }
  
  ll ans = 0;
  for(int bit = 0; bit < (1 << n); bit++){
    string keep1, keep2;
    for(int i = 0; i < n; i++){
      if(bit & (1 << i)) keep1 = keep1 + t2.at(i);
      else keep2 = keep2 + t2.at(i);
    }
    ans += mp[make_pair(keep1, keep2)];
  }
  
  cout << ans << '\n';
}