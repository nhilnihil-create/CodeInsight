#include <bits/stdc++.h>
using namespace std;
static const int MOD=1000000007;

int main(){
  int H,W;
  cin>>H>>W;
  string S;
  char D[1010][1010];
  for(int i=0;i<H;i++){
    cin>>S;
    for(int j=0;j<W;j++){
      D[i][j]=S.at(j);
    }
  }
  int dp[1010][1010]={};
  dp[0][0]=1;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(i==0 && j==0) continue;
      if(D[i][j] =='#'){
        dp[i][j]=0;
        continue;
      }
      if(D[i][j]=='.' && i == 0 && j>0){
        dp[i][j]=dp[i][j-1];
      }
      else if(D[i][j]=='.' && i> 0 && j ==0){
        dp[i][j]=dp[i-1][j];
      }
      else if(D[i][j]=='.' && i> 0 && j>0){
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
      }
    }
  }
  cout<<dp[H-1][W-1]<<endl; 
  /*for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<dp[i][j]<<D[i][j];
    }
    cout<<endl;
  }*/
 
  return 0;
}
