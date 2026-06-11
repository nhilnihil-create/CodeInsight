#include<bits/stdc++.h>
using namespace std;

int dp[305][305][305];

int main(){
  
  string s;
  int K;
  
  cin>>s>>K;
  
  memset(dp,-1,sizeof(dp));
  
  dp[0][s.size()-1][0]=0;
  
  int ans=0;
  
  for(int l=0;l<s.size();l++)
    
    for(int r=s.size()-1;r>=l;r--){

      for(int k=0;k<=K;k++){
	
	if(dp[l][r][k]==-1) continue;
	
	if(s[l]==s[r]){
	  if(l==r) ans=max(ans, dp[l][r][k]+1);
	  else{
	    dp[l+1][r-1][k]=max(dp[l+1][r-1][k], dp[l][r][k]+2);
	    ans=max(ans, dp[l+1][r-1][k]);
	  }
	}
	
	if(l==r) continue;
	
	if(k<K){
	  dp[l+1][r-1][k+1]=max(dp[l+1][r-1][k+1], dp[l][r][k]+2);
	  ans=max(ans, dp[l+1][r-1][k+1]);
	}
	
	dp[l+1][r][k]=max(dp[l+1][r][k], dp[l][r][k]);
	dp[l][r-1][k]=max(dp[l][r-1][k], dp[l][r][k]);
	dp[l+1][r-1][k]=max(dp[l+1][r-1][k], dp[l][r][k]);
      }
    }
  
  cout<<ans<<endl;
  
  return 0;
}
