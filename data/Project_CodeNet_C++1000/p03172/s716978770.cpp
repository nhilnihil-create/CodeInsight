#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int> &v, int n, int k){
  ll dp[n+2][k+2];
  memset(dp, 0, sizeof dp);

  for(int j=0;j<=k;j++){
      dp[1][j]=(j>v[1])?0:1;
  }
    for(int i=2;i<=n;++i){
        for(int j=0;j<=k;++j){
            if(j==0){
                     dp[i][0]=dp[i-1][0];
            }
            else{
                dp[i][j]=  (1000000007+dp[i][j-1] + dp[i-1][j] - ((j-v[i]-1>=0)?dp[i-1][j-v[i]-1]:0))%1000000007;
            }
        }
    }
   return dp[n][k];


}
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=1;i<=n;++i){
        cin>>v[i];
    }
    cout<<solve(v,n,k);
    return 0;}