#include<bits/stdc++.h>
using namespace std;
using Int = long long;
signed main(){
  string s;
  cin>>s;
  int n=s.size();
  vector<int> v(n+1,0),dp(n+1,n+1),m(1<<26,n+1);
  for(int i=0;i<n;i++)
    v[i+1]=v[i]^(1<<(s[i]-'a'));
  dp[0]=0;
  for(int i=0;i<=n;i++){
    int b=v[i];
    m[b]=min(m[b],dp[i]);
    dp[i]=min(dp[i],m[b]+1);
    for(int j=0;j<26;j++)
      dp[i]=min(dp[i],m[b^(1<<j)]+1);
    m[b]=min(m[b],dp[i]);
  }
  cout<<dp[n]<<endl;
  return 0;
}
