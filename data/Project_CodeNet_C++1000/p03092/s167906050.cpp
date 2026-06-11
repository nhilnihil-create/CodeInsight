#include<bits/stdc++.h>
using namespace std;
int pos[5000];
long long dp[6000][6000];
int main(){
  int n;
  long long a,b;
  scanf("%d%lld%lld",&n,&b,&a);
  for(int i=0;i<n;i++){
    int p;
    scanf("%d",&p);
    pos[p]=i+1;
  }
  for(int i=0;i<n+1;i++){
      if(i<pos[1])
        dp[1][i]=a;
      else
        dp[1][i]=0ll;
  }
  for(int x=2;x<=n;x++){
    for(int i=0;i<n+1;i++){
      dp[x][i] = (long long)1e18;
      if(i<pos[x])
        dp[x][i] = min(dp[x][i],a+dp[x-1][i]);
      else{
          dp[x][i] = min(dp[x][i], dp[x-1][pos[x]-1]);
          dp[x][i] = min(dp[x][i], b+dp[x-1][i]);
      }
    }
  }
  printf("%lld\n",dp[n][n]);
}
