#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin>>n>>m;
  vector<long> a(n),dp(n+1,0);
  map<int,long> mp;
  mp[0]=1;
  for(int i=0;i<n;i++){
    cin>>a[i];
    dp[i+1]=dp[i]+a[i];
    dp[i+1]%=m;
    mp[dp[i+1]]++;
  }
  long ans=0;
  for(auto p:mp){
    ans+=p.second*(p.second-1)/2;
  }
  cout<<ans<<endl;
}
