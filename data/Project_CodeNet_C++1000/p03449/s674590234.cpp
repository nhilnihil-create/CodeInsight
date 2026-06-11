#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<vector<int>>A(N,vector<int>(2));
  for(int i=0;i<2;i++){
    for(int j=0;j<N;j++)cin>>A[j][i];
  }

  vector<vector<int>>dp(N,vector<int>(2,0));
  dp[0][0]=A[0][0];
  for(int i=0;i<N;i++){
    for(int j=0;j<2;j++){
      if(i==0&&j==0)continue;
      if(i-1>=0)dp[i][j]=max(dp[i][j],dp[i-1][j]+A[i][j]);
      if(j-1>=0)dp[i][j]=max(dp[i][j],dp[i][j-1]+A[i][j]);
    }
  }
  cout<<dp[N-1][1]<<endl;
  return 0;
}
