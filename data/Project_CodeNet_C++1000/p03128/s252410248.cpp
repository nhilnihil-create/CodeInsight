#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long

//int match[10] = {6,2,5,5,4,5,6,3,7,6};
string match = "6255456376";

signed main(){

  int n,m; cin >> n >> m;
  vector<char> a(m);
  for(int i = 0; i < m; i++) cin >> a[i];
  // sort(a.rbegin(),a.rend(),[&](char x,char y){
  //   int a = x - '0';
  //   int b = y - '0';
  //   return match[a] < match[b];
  // });

  vector<string> dp(n+10,"INF");
  dp[0] = "";
  auto f = [&](string s,string t){
    if(s == "INF") return t;
    else if(s.size() < t.size()) return t;
    else if(s.size() > t.size()) return s;
    else {
      for(int i = 0; i < s.size(); i++){
        if((int)(s[i] - '0') > (int)(t[i] - '0')){
          return s;
        }
        if((int)(s[i] - '0') < (int)(t[i] - '0')){
          return t;
        }
      }
    }
    return s;
  };
  for(int i = 0; i <= n; i++){
    for(int j = 0; j < m; j++){
      if(dp[i] == "INF") continue;
      char c = match[(int)(a[j] - '0')];
      int p = (int)(c - '0');
      dp[i + p] = f(dp[i + p],dp[i] + a[j]);
      // if(i-p == 0 && dp[i-p] == "") dp[i] = a[j];
      // if(i-p > 0 && dp[i-p] != "") dp[i] = f(dp[i],dp[i-p] + a[j]);
    }
  }
  cout << dp[n] << endl;

  return 0;
}
