#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
// #define m 1003
// #define int long long

// int sol(vector<int> A){


// }


int32_t main(){
  IOS
int n,k;
cin>>n>>k;
int h[n];
for(int i=0;i<n;i++) cin>>h[i];
int t =0;

int ans = 0;
int dp[n+1];
for(int i=0;i<=n;i++) dp[i]= INT_MAX;
dp[1]=0;
  for(int i=1;i<=n;i++){
    for(int j = i+1;j<=n&&j<=i+k;j++){
      dp[j] = min(dp[j],dp[i]+ abs(h[j-1]-h[i-1]));
    }
  }
  cout <<dp[n];


 return 0;
}

 