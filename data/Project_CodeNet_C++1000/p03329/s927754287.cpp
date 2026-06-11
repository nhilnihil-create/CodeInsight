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
  vector<int>dp(1000005,INF);
  dp[1]=1;
  dp[0]=0;
  for(int j=0;j<N;j++){
    int64_t a=1,b=1;
    for(int i=0;i<10;i++){
      if(j+a*6<=N){a*=6;}
      if(j+b*9<=N){b*=9;}
      chmin(dp[j+a],dp[j]+1);
      chmin(dp[j+b],dp[j]+1);
      chmin(dp[j+1],dp[j]+1);
    }
  }
  //for(int i=1;i<100;i++){
  //  cout<<i<<" "<<dp[i]<<endl;
  //}
  cout<<dp[N]<<endl;
  return 0;  
}