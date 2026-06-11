#include<bits/stdc++.h>
using namespace std;
long long int dp[1001][1001];
#define MOD 1000000007

int main(){
      int h, w;
      cin>>h>>w;
      memset(dp, 0, sizeof(dp));
      dp[0][1]=1;
      for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                  char a;
                  cin>>a;
                  
                  if(a=='.')
                        dp[i][j]=1;
                  else dp[i][j]=0;
            }
      }
      for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                  if(dp[i][j]==1)dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
      }
      cout<<dp[h][w]<<'\n';
}