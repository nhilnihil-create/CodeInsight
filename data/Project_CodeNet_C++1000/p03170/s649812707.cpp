#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int dp[k+1]={0};
  for(int i=1;i<=k;i++){
    for(int j=0;j<n;j++){
      if(a[j]<=i){
        if(dp[i-a[j]]==0)
          dp[i]=1;
      }
    }
  }
  if(dp[k]==1) cout<<"First";
  else cout<<"Second";
  return 0;
}