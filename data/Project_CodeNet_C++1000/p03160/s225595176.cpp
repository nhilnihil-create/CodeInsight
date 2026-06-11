#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n; cin>>n;
  vector<int> v(n); rep(i,n) cin>>v[i];
  int dp[n];
  dp[0] = 0;
  dp[1] = abs(v[1]-v[0]);
  for(int i=2; i<n; i++){
  	dp[i] = min(dp[i-2] + abs(v[i]-v[i-2]), dp[i-1] + abs(v[i]-v[i-1]));
  }
  cout << dp[n-1] << endl;
}