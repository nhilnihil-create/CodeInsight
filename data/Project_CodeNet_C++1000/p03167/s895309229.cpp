#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    int h,w;
    cin>>h>>w;
    vector<vector<char>> path(h,vector<char>(w));
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++) cin>>path[i][j];
      }
     vector<vector<long long int>> dp(h,vector<long long int>(w));
     dp[0][0]=1;
      for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(path[i][j]=='.'){
                if(j-1>=0){
                    dp[i][j]=dp[i][j-1];
                }
                if(i-1>=0) dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;

            }
        }
      }
      cout<<dp[h-1][w-1];
}
