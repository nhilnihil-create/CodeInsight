#include<bits/stdc++.h>
using namespace std;
bool dp[101][100001];
int main(){
  int n,k;
  cin>>n>>k;
  int a[n+1];
  for(int i=1;i<=n;i++)
  cin>>a[i];
  memset(dp,0,sizeof dp);
  for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
          if(j<a[i])
          dp[i][j]=dp[i-1][j];
          else { for(int k=1;k<=i;k++)
              dp[i][j]=max(!dp[i][j-a[k]],dp[i][j]);
          }
      }
  }
  if(dp[n][k])
  cout<<"First";
  else cout<<"Second";
  return 0;
}