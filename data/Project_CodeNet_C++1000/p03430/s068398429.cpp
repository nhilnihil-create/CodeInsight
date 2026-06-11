#include<bits/stdc++.h>
using namespace std;

int dp[305][305][305];

int main(){
  
  string s;
  int K;
  
  cin>>s>>K;
  
  memset(dp,-1,sizeof(dp));

  s='x'+s;
  
  int len=s.size();
  
  dp[1][len-1][0]=0;
  
  for(int l=1;l<len;l++)
    
    for(int r=len-1;r>=l;r--){
      
      for(int k=0;k<=K;k++){
	
	if(dp[l][r][k]==-1) continue;
	
	if(s[l]==s[r]){
	  if(l==r) dp[l+1][r-1][k]=max(dp[l+1][r-1][k], dp[l][r][k]+1);
	  else dp[l+1][r-1][k]=max(dp[l+1][r-1][k], dp[l][r][k]+2);
	}
	
	if(l==r) continue;
	
	dp[l+1][r-1][k+1]=max(dp[l+1][r-1][k+1], dp[l][r][k]+2);
	dp[l+1][r][k]=max(dp[l+1][r][k], dp[l][r][k]);
	dp[l][r-1][k]=max(dp[l][r-1][k], dp[l][r][k]);
	dp[l+1][r-1][k]=max(dp[l+1][r-1][k], dp[l][r][k]);
      }
    }
  
  int ans=0;
  
  for(int i=0;i<=len;i++)
    for(int j=0;j<=len;j++)
      for(int k=0;k<=K;k++) ans=max(ans, dp[i][j][k]);
  
  cout<<ans<<endl;
  
  return 0;
}
