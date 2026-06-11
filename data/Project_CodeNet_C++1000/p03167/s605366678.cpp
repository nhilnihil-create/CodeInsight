#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  int r,c;
  const int mod=1e9+7;
  cin>>r>>c;
  vector<vector<char>> grid(r,vector<char> (c));
  vector<vector<ll>> dp(r,vector<ll> (c,0));
  for(int i=0;i<r;i++){
  	for(int j=0;j<c;j++){
    	cin>>grid[i][j];
    }
  }
  for(int i=1;i<r;i++){
      
      if(grid[i][0]!='#')
      dp[i][0]=1;
      else break;
  }
  for(int i=0;i<c;i++){
  	if(grid[0][i]!='#')
      dp[0][i]=1;
    else break;
  }
  for(int i=1;i<r;i++){
  	for(int j=1;j<c;j++){
    	if(grid[i][j]=='#')	
      	    dp[i][j]=0;
      	else{
        	dp[i][j]=(dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
  }
  cout<<dp[r-1][c-1]<<endl;
  return 0;
  
  
}
