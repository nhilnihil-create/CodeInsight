#include<bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<string,string> P;

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;

  map<P,int> mp;
  for(int i = 0; i < 1 << n; i++){
    string red,blue;
    for(int j = 0; j < n; j++){
      if(1 & i >> j) red += s[j];
      else blue += s[j];
    }
    mp[P(red,blue)] += 1;
  }

  int ans = 0;
  for(int i = 0; i < 1 << n; i++){
    string red,blue;
    for(int j = 0; j < n; j++){
      if(1 & i >> j) red += s[n+j];
      else blue += s[n+j];
    }

    reverse(red.begin(),red.end());
    reverse(blue.begin(),blue.end());
    if(mp.find(P(red,blue)) != mp.end()){
      ans += mp[P(red,blue)];
    }
  }
  cout << ans << endl;

  return 0;
}
