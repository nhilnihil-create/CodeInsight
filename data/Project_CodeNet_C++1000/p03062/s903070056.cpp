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
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const int inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  vector<lint> a(n+1,0);
  vector<vector<lint>> dp(n+5,vector<lint>(3,0));
  rep1(i,n)cin>>a[i];
  dp[1][0]=a[1];
  dp[2][0]=a[1]+a[2];
  dp[2][1]=-a[1]-a[2];
  for(int i=3;i<=n;++i){
      dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i];
      dp[i][1]=max(dp[i-1][0]-2*a[i-1],dp[i-1][1]+2*a[i-1])-a[i];
  }
  cout<<max(dp[n][0],dp[n][1])<<"\n";
  return 0;
}