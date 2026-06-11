#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int n,ans;
  int a[100005][5];
  int dp[100005][5]={};
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=0;j<3;j++){
      cin>>a[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
    dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
    dp[i][2]=max(dp[i-1][1],dp[i-1][0])+a[i][2];
  }
  ans=max(dp[n][0],max(dp[n][1],dp[n][2]));
  cout<<ans<<"\n";
  return 0;
}
