#include<bits/stdc++.h>
using namespace std;

int frog2(int*s, int n, int k){
  int dp[100005];
  dp[1]=0;
  for(int i=2;i<=n;i++){
    dp[i] = INT_MAX;
  	for(int j=i-1; j>=1 && (i-j)<=k; j--){
    	dp[i] = min(dp[i],abs(s[i]-s[j]) + dp[j]);
    }
  }
  return dp[n];
}

int main(){
  int n,k;	cin>>n>>k;
  int a[100006];
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  cout<<frog2(a,n,k);
  return 0;
}