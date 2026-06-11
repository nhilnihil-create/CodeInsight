#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  int dp[k+1];
  memset(dp,0,sizeof dp);
  for(int i=0; i<=k; i++){
    for(int j=0; j<n; j++){
        if(i-a[j]>=0){
            if(dp[i-a[j]]==0){
                dp[i]=1;
            }
        }
    }
  }
  if(dp[k]==1){cout<<"First";}
  else{cout<<"Second";}
  return 0;
}