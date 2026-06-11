#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
const int inf=1000000007;
const int MOD=1000000007;
int dp[3][100050]={};
int dpr[3][100050]={};
signed main(){
  string s;cin>>s;
  int n=(int)s.length();
  int res=0;
  dp[1][0]=0;
  int q=1;
  if(s[0]=='A'||s[0]=='?'){
    dp[1][0]=1;
    if(s[0]=='?')q=3;
  }
  dp[2][0]=0;
  int rate=1;
  rep1(i,n-1){
    if(s[i]=='?'){
      res*=3;
      res+=dp[2][i-1];
      dp[2][i]=dp[2][i-1]*3+dp[1][i-1];
      dp[1][i]=dp[1][i-1]*3+q;
      q*=3;q%=MOD;
    }
    else{
      if(s[i]=='C'){
        res+=dp[2][i-1];
        dp[2][i]=dp[2][i-1];
        dp[1][i]=dp[1][i-1];
      }
      else if(s[i]=='B'){
        dp[2][i]=dp[2][i-1]+dp[1][i-1];
        dp[1][i]=dp[1][i-1];
      }
      else if(s[i]=='A'){
        dp[2][i]=dp[2][i-1];
        dp[1][i]=dp[1][i-1]+q;
      }
    }
    //cout<<res<<endl;
    res%=MOD;
    dp[1][i]%=MOD;dp[2][i]%=MOD;
  }
  cout<<res<<endl;
  rep(i,n){
    //printf("dp[1][%d]=%d, dp[2][%d]=%d\n",i,dp[1][i],i,dp[2][i]);
    //printf("dp[1][%lld]=%lld, dp[2][%lld]=%lld\n",i,dp[1][i],i,dp[2][i]);
  }
  return 0;
}