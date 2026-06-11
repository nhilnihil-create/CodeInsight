#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

// 最小の分割数
unordered_map<int,int> dp;
const int INF=INT_MAX/2;

int main(){
  string S; cin>>S;
  int n=S.length();
  int a=0;
  dp[0]=0;
  rep(i,n){
    a^=(1<<(S[i]-'a'));
    if(!dp.count(a)) dp[a]=INF;
    rep(j,26){
      int x=a^(1<<j);
      if(dp.count(x)) dp[a]=min(dp[a],dp[x]+1);
    }
  }
  cout<<max(1,dp[a])<<endl;
  return 0;
}
