#include<bits/stdc++.h>
using namespace std;
long long int a[105];
#define mod 1000000007

int main(){
      int n, k;
      cin>>n>>k;
      for(int i=0; i<n; i++)
            cin>>a[i+1];
      vector<int>prefix(k+1, 1);
      int dp[n+1][k+1];
      for(int i=0; i<=n; i++)
            for(int j=0; j<=k; j++)
                  dp[i][j]=0;
      dp[0][0]=1;

      for(int i=1; i<=n; i++){
            /*vector<int>pre(k+1);

            for(int p=0; p<=k; p++){
                  if(p-a[i]-1<0)
                        dp[i][p]=prefix[p];
                  else {
                        dp[i][p]=(prefix[p]-prefix[p-a[i]-1]+mod)%mod;
                  }
                  //cout<<i<<' '<<p<<' '<<dp[i][p]<<'\n';

                  if(p>0)pre[p]=dp[i][p]+pre[p-1];
                  else pre[p]=1;
            }
            prefix=pre;*/
            int sums[k+1];
        sums[0]=dp[i-1][0];
        for(int j=1;j<=k;j++)
        {
            sums[j]=(sums[j-1]+dp[i-1][j])%mod;  ///Calculate the prefix sums for i-1
        }
        for(int j=0;j<=k;j++)
        {
            int tr=sums[j];  ///Sum of dp[i-1][0...j]
            int unreachable=j-a[i]-1;  ///We need to subtract the sum of the first "unreachable" elements (dp[i-1][0...unreachable])
            if(unreachable>=0)
            {
                tr=(tr-sums[unreachable]+mod)%mod;  ///Add mod to make sure that "tr-sums[unreachable]" is not negative.
            }
            dp[i][j]=tr;
        }
      }
      cout<<dp[n][k];
}