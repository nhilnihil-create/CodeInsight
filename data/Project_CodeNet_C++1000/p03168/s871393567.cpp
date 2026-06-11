#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;
int main() {
  int N;
  cin>>N;
  vector<double>p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  vector<vector<double>>dp(N+1,vector<double>(N+1));
  dp[0][0]=1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(j==0){dp[i+1][j]=dp[i][j]*(1-p[i]);}
      dp[i+1][j+1]=dp[i][j]*(p[i])+dp[i][j+1]*(1-p[i]);
    }
  }
  double ans=0;
  for(int j=N/2+1;j<=N;j++){
    ans+=dp[N][j];
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;  
}