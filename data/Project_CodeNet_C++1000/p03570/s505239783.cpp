#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define ll int
int dp[1<<26]={0};
int main(){
  string s;
  cin>>s;
  vector<ll> hs;
  ll now_h=0;
  ll n=s.length();
  for(int i=0;i<n;i++){
    ll c=(ll)(s[i]-'a');
    now_h^=((ll)1<<c);
    hs.push_back(now_h);
  }
  for(int i=0;i<(1<<26);i++) dp[i]=17441744;
  dp[0]=0;
  if(now_h==0){
    cout<<1<<endl;
    return 0;
  }
  for(int i=0;i<26;i++) {
    if(now_h==(1<<i)) {
      cout<<1<<endl;
      return 0;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<26;j++){
      dp[hs[i]]=min(dp[hs[i]],dp[hs[i]^(1<<j)]);
    }
    dp[hs[i]]++;
    dp[0]=0;
  }
  cout<<dp[hs[n-1]]<<endl;
}
