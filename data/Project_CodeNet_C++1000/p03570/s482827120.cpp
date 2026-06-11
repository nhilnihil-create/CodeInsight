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
  map<int,int> mm;
  dp[0]=0;
  for(int i=0;i<=n;i++){
    int b=v[i];
    if(!mm.count(b)) mm[b]=dp[i];
    mm[b]=min(mm[b],dp[i]);
    dp[i]=min(dp[i],mm[b]+1);
    for(int j=0;j<26;j++){
      b^=(1<<j);
      //if(mm.count(b)) cout<<i<<":"<<b<<" "<<mm[b]<<endl;
      if(mm.count(b)) dp[i]=min(dp[i],mm[b]+1);
      b^=(1<<j);
    }
    mm[b]=min(mm[b],dp[i]);
    //cout<<i<<":"<<dp[i]<<" "<<bitset<26>(b)<<endl;
    if(i<n) dp[i+1]=min(dp[i+1],dp[i]+1);
  }
  cout<<dp[n]<<endl;
  return 0;
}
