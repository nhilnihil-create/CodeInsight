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
string LCS(string s,string t){
  int sn=s.length();
  int tn=t.length();
  vector<vector<int>> dp(sn,vector<int>(tn,0));
  int flag=0;
  for(int i=0;i<sn;++i){
      if(s[i]==t[0])flag=1;
      dp[i][0]=flag;
  }
  flag=0;
  for(int i=0;i<tn;++i){
      if(s[0]==t[i])flag=1;
      dp[0][i]=flag;
  }
  for(int i=1;i<=sn-1;++i){
      rep1(j,tn-1){
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          if(s[i]==t[j])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
      }
  }
  string res;
  int i=sn-1;int j=tn-1;
  while(true){
      while(j>0&&dp[i][j]==dp[i][j-1])--j;
      while(i>0&&dp[i][j]==dp[i-1][j])--i;
      if(s[i]==t[j])res+=s[i];
      if(i>0)--i;else break;
      if(j>0)--j;else break;
  }
  reverse(ALL(res));
  return res;
}
signed main(){
  string s,t;cin>>s>>t;
  cout<<LCS(s,t)<<"\n";
  return 0;
}