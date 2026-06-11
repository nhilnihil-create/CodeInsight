#include <bits/stdc++.h>
using namespace std;
 //https://atcoder.jp/contests/dp/tasks/dp_b
int main(){
  int n,k; cin>>n>>k;
  int h[n];
  for(int i=0; i<n; i++) cin>>h[i];
  vector<int> dp(n, 0);
  for(int i=1; i<n; i++){
    int mn=1e9+1;
    for(int j=1; j<=k; j++){//going backwards
      if(i-j>=0)
        mn=min(mn, abs(h[i]-h[i-j])+dp[i-j]);
    }
    dp[i]+=mn;
  }
  cout<<dp[n-1]<<endl;
  return 0;
}
