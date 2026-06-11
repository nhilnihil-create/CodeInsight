#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>>a(H+1,vector<char>(W+1));
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin>>a[i][j];
    }
  }
  vector<vector<int>>dp(H+1,vector<int>(W+1));
  dp[1][1]=1;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      if(!(i==1&&j==1)){
        if(a[i][j]=='#'){dp[i][j]=0;}
        else{dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;}
      }
    }
  }

  cout<<dp[H][W]<<endl;
  return 0;  
}