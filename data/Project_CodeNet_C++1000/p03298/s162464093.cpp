#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  string s;cin>>s;
  ll ans=0;
  for(ll i=0;i<1<<n;i++){
    vector<char> r={'a'},b={'a'};
    ll u=i;
    for(ll j=0;j<n;j++){
      if(u%2==0)r.push_back(s[j]);
      else b.push_back(s[j]);
      u/=2;
    }
    ll rs=r.size()-1,bs=b.size()-1;
    //if(i==6){
      //for(ll ii=0;ii<bs;ii++)cout<<b[ii]<<" ";
      //return 0;
    //}
    ll dp[n+1][bs+1][rs+1];
    for(ll j=0;j<=n;j++)for(ll k=0;k<=bs;k++)for(ll l=0;l<=rs;l++)dp[j][k][l]=0;
    dp[0][0][0]=1;
    for(ll j=2*n;j>n;j--){
      ll num=2*n-j;
      for(ll k=0;k<=num;k++){
        if(k>bs||num-k>rs)continue;
        if(k<bs){
          if(s[j-1]==b[k+1]){
            dp[num+1][k+1][num-k]+=dp[num][k][num-k];
          }
        }
        if(num-k<rs){
          if(s[j-1]==r[num-k+1]){
            dp[num+1][k][num-k+1]+=dp[num][k][num-k];
          }
        }
      }
    }
    ans+=dp[n][bs][rs];
    //if(i==6)for(ll j=0;j<=n;j++)for(ll k=0;k<=bs;k++)for(ll l=0;l<=rs;l++)cout<<dp[j][k][l]<<endl;
    
  }
  cout<<ans<<endl;
}