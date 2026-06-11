#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  string s;cin>>s;
  vector<vector<int>> dp(n+5,vector<int>(n+5,0));
  rep1(i,n)dp[1][i]=1;
  rep1(i,n-1){
      char sign=s[i-1];
      if(sign=='>'){
          rep1(j,n){
              dp[i+1][1]+=dp[i][j];
              dp[i+1][j]+=MOD-dp[i][j];
          }
      }
      else{
          rep1(j,n){
              dp[i+1][n+1-i]+=MOD-dp[i][j];
              dp[i+1][j]+=dp[i][j];
          }
      }
      rep1(j,n){
          dp[i+1][j]=dp[i+1][j-1]+dp[i+1][j];
          dp[i+1][j]%=MOD;
      }
  }
  cout<<dp[n][1]<<"\n";
  return 0;
}