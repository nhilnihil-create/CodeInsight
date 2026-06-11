//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <climits>

using namespace std;
using ll=long long;

void solve(){
  string str;
  cin >> str;
  int mod=(int)1e9+7;
  std::vector<ll> dp(4);
  dp[0]=1;
  for(int i=0;i<str.length();i++){
    vector<ll> newdp(4);
    for(int j=0;j<4;j++){
      if(j!=3&&(str[i]-'A'==j||str[i]=='?'))
        newdp[j+1]=dp[j];
      newdp[j]=(newdp[j]+(str[i]=='?'?3:1)*dp[j])%mod;
    }
    dp=newdp;
  }
  cout << dp[3] << endl;
}

int main(){
  solve();
  return 0;
}
