#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

void solve(){
  int n,m;
  
  scanf("%d",&n);
  int A[n];
  ll dp[n+2]={};
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for (int i = 1; i < n+2; i++)
  {
    dp[i]=INT_MAX;
  }
  dp[0]=0;
  dp[1]=abs(A[1]-A[0]);
  for(int i=2;i<n;i++){
      dp[i]=min(dp[i-1]+abs(A[i]-A[i-1]),dp[i-2]+abs(A[i]-A[i-2]));
   }
  


  printf("%lld\n",dp[n-1]);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}