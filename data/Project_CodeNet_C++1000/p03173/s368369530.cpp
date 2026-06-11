#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int64_t> s(n+1,0);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    s.at(i+1)=s.at(i)+a;
  }
  vector<vector<int64_t>> dp(n,vector<int64_t>(n,0));
  for(int w=1;w<n;w++){
    for(int i=0;i+w<n;i++){
      dp[i][i+w]=dp[i+1][i+w];
      for(int x=i;x<i+w;x++)
        dp[i][i+w]=min(dp[i][i+w],dp[i][x]+dp[x+1][i+w]);
      dp[i][i+w]+=s.at(i+w+1)-s.at(i);
    }
  }
  cout<<dp[0][n-1]<<endl;
}