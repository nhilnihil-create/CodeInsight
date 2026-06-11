#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

const ll mod=1e9+7;
ll mu(ll a,ll b){
  return (ll)a*b%mod;
}
ll ad(ll a,ll b){
  if((a+=b)>=mod)a-=mod;
  return a;
}
ll pw(ll a,ll b,ll c=1LL){
  for(;b;b>>=1,a=mu(a,a))if(b&1)c=mu(c,a);
  return c;
}
ll dv(ll a,ll b){
  return mu(a,pw(b,mod-2));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  ll n=s.size();
  ll dp[n+1][4];
  
  rep(i,n+1)rep(j,4) dp[i][j]=0;
  dp[0][0]=1;
  rep1(i,n){
    dp[i][0]=dp[i-1][0];
    if(s[i-1]=='?') dp[i][0] = mu(dp[i][0],3LL);
    
    dp[i][1]=dp[i-1][1];
    if(s[i-1]=='?') dp[i][1] = mu(dp[i][1],3LL);    
    if(s[i-1]=='A'||s[i-1]=='?'){
      dp[i][1]+=dp[i-1][0];
      dp[i][1]%=mod;
    }

    dp[i][2]=dp[i-1][2];
    if(s[i-1]=='?') dp[i][2] = mu(dp[i][2],3LL);
    if(s[i-1]=='B'||s[i-1]=='?'){
      dp[i][2]+=dp[i-1][1];
      dp[i][2]%=mod;
    }

    dp[i][3]=dp[i-1][3];
    if(s[i-1]=='?') dp[i][3] = mu(dp[i][3],3LL);
    if(s[i-1]=='C'||s[i-1]=='?'){
      dp[i][3]+=dp[i-1][2];
      dp[i][3]%=mod;
    }
    //    cout << dp[i][0] << " " << dp[i][1] <<	" "<< dp[i][2] <<	" "<< dp[i][3] <<	" " << endl;
  }
  cout << dp[n][3] << endl;


  
  return 0;
    

}
