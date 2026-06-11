#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
// #define mp make_pair
#define S second
#define F first
// ll mod=1e9+7 ;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define input_from_file  freopen("input.txt", "r", stdin);
using namespace std::chrono; 

int main(){                fastIO
  // input_from_file
  ll n;cin>>n;ll vec[n][3];
  for(int i=0;i<n;i++) cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
  ll dp[n][3];dp[0][0]=vec[0][0];dp[0][1]=vec[0][1];dp[0][2]=vec[0][2];
  for(int i=1;i<n;i++){
    dp[i][0]=vec[i][0]+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1]=vec[i][1]+max(dp[i-1][2],dp[i-1][0]);
    dp[i][2]=vec[i][2]+max(dp[i-1][0],dp[i-1][1]);
  }
  cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
  return 0;
}