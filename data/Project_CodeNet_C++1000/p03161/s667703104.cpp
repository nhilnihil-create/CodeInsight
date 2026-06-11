#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int Go(int *a,int n,int k){
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=0;i<n;i++) 
     for(int j=i+1;j<n && j<=i+k;j++)
       dp[j]=min(dp[j],dp[i]+abs(a[j]-a[i]));
    return dp[n-1];
}

int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  cout<<Go(a,n,k)<<endl;
  return 0;
}