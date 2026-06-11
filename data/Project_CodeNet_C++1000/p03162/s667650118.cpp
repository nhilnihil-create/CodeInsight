#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int dp[100005][3];

int sol(int i,int l,int n,int A[][3]){
  if(dp[l][i]!=-1) return dp[l][i];
  if(l==n) return A[n-1][i];

  if(i==0){
    dp[l][i]= A[l-1][i] +max(sol(1,l+1,n,A),sol(2,l+1,n,A));
    return dp[l][i];
  }
  if(i==1){
    dp[l][i]= A[l-1][i] +max(sol(0,l+1,n,A),sol(2,l+1,n,A));
    return dp[l][i];
  }
  if(i==2){
    dp[l][i]= A[l-1][i] +max(sol(0,l+1,n,A),sol(1,l+1,n,A));
    return dp[l][i];
  }

}




int32_t main(){
IOS
int n;
cin>>n;
int A[n][3];
memset(dp,-1,sizeof(dp));
for(int i=0;i<n;i++){
  for(int j=0;j<3;j++){
    cin>>A[i][j];
  }
}

int mx=0;
for(int i=0;i<3;i++){
  mx = max(mx,sol(i,1,n,A));
}
  cout <<mx<<endl;


 return 0;
}

 