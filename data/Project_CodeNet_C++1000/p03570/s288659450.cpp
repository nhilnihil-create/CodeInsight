#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  string s;
  cin>>s;
  int n=s.size();
  vector<int> v(n+1);
  v[0]=0;
  for(int i=0;i<n;i++){
    v[i+1]=v[i]^(1<<(s[i]-'a'));
  }
  vector<int> dp(n+1,1<<28);
  map<int,int> m;
  dp[0]=0;
  for(int i=0;i<=n;i++){
    int b=v[i];
    if(!m.count(b)) m[b]=dp[i];
    m[b]=min(m[b],dp[i]);
    dp[i]=min(dp[i],m[b]+1);
    for(int j=0;j<26;j++){
      b^=(1<<j);
      if(m.count(b)) dp[i]=min(dp[i],m[b]+1);
      b^=(1<<j);
    }
    m[b]=min(m[b],dp[i]);
  }
  cout<<dp[n]<<endl;
  return 0;
}
