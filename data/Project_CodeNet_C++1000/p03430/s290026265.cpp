#include <bits/stdc++.h>
using namespace std;

int main()
{
  char s[310];
  scanf("%s",s);
  int n=strlen(s);
  int k;
  scanf("%d",&k);
  static int dp[310][310][310];
  int ans=1;
  for(int j=0;j<=n;j++){
    for(int i=0;i+j<=n;i++){
      for(int l=0;l<=k;l++){
	if(j==0||j==1){
	  dp[i][j][l]=j;
	  continue;
	}
	dp[i][j][l]=max(dp[i][j-1][l],dp[i+1][j-1][l]);
	if(s[i]==s[i+j-1]){
	  dp[i][j][l]=max(dp[i][j][l],dp[i+1][j-2][l]+2);
	}
	if(l>0){
	  dp[i][j][l]=max(dp[i][j][l],dp[i+1][j-2][l-1]+2);
	}
	ans=max(ans,dp[i][j][l]);
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}

	
