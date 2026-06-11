#include<bits/stdc++.h>
using namespace std;
long double p[3000];
long double dp[3000][1501];

int main(){
      int n;
      cin>>n;
      for(int i=0; i<n; i++)
            {cin>>p[i+1];p[i+1]=1-p[i+1];/*cout<<p[i+1]<<" ";*/}
      
      dp[0][0]=1;
      dp[0][1]=0;

      for(int i=1; i<(n+1)/2; i++)
            dp[0][i]=0;

      for(int i=1; i<=n; i++){
            for(int j=0; j<(n+1)/2; j++){
                  dp[i][j]=(dp[i-1][j]*(1-p[i]))+(dp[i-1][j-1]*p[i]);
                  //cout<<i<<" "<<j<<' '<<dp[i][j]<<'\n';
            }
            //cout<<'\n';
      }
      for(int i=1; i<(n+1)/2; i++)
            {dp[n][i]+=dp[n][i-1];}

      cout<<fixed<<setprecision(10)<<dp[n][(n+1)/2-1];
}