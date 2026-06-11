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
  vector<int> c(n+1,0);
  map<int,int> memo;
  rep1(i,n){
      cin>>c[i];
  }
  int res=1;
  vector<int> dp(n+1,0);
  dp[0]=1;
  rep1(i,n){
      dp[i]=dp[i-1];
      auto it=memo.find(c[i]);
      if(it!=memo.end()&&it->second!=i-1){
          dp[i]+=dp[it->second];
      }
      else{
          ;
      }
      dp[i]%=MOD;
      memo[c[i]]=i;
  }
  rep1(i,n){
      //cout<<dp[i]<<" ";
  }
  //cout<<endl;
  cout<<dp[n]<<endl;
  return 0;
}