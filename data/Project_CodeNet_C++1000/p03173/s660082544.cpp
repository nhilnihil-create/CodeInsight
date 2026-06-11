#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
vector<long int> sum;
long int dp[1000][1000];

long int solve(vector<int>& a,int i, int j) {
  if (i==j) return 0;
  if (dp[i][j]!=-1) return dp[i][j];
  long int soln = LONG_MAX;
  for (int k=i;k<j;k++) {
    long int temp = (0ll + solve(a,i,k) + solve(a,k+1,j) + sum[j+1] - sum[i+1] +a[i]);
    
    soln = min(soln, temp);
  }
  return dp[i][j] = soln;
}


int main() {
  cin>>n;
  vector<int> a(n);
  sum = vector<long int>(n+1,0);
  for (int i=0;i<n;i++) {
    cin>>a[i];
    sum[i+1] = sum[i]+a[i];
  }
  
  memset(dp,-1,sizeof(dp));
  cout<<solve(a,0,n-1);
  
  return 0;
}
