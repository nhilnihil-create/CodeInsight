#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  
  int x;
  int B[10]={0,2,5,5,4,5,6,3,7,6};
  vector<int> A(10),C(10);
  rep(i,m){
    cin>>x;
    A[x]=1;
    C[B[x]]=1;
  }
  
  int dp[10010];
  rep(i,10010) dp[i]=-1;
  dp[0]=0;
  
  for(int i=2;i<=n;i++){
    for(int j=2;j<=7;j++){
      if(C[j]==1 && i-j>=0 && dp[i-j]!=-1 && dp[i]<dp[i-j]+1) dp[i]=dp[i-j]+1;
    }
  }
    
  for(int i=9;i>0;i--){
    if(A[i]==0) continue;
    while(n-B[i]>=0 && dp[n-B[i]]==dp[n]-1){
      cout<<i;
      n-=B[i];
    }
  }
  cout<<endl;
  
  return 0;
}