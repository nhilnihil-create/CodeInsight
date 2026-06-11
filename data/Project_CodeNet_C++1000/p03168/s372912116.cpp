#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int tar = (n-1)/2 +1;
  vector<double> pn(n);
  for(int i=0; i<n; ++i) cin >> pn[i];
  vector<double> dp(tar+1,0);
  dp[0] = 1;
  for(int i=0; i<n; ++i) for(int j=min(i+1,tar); j>=0; --j){
    if(j == tar) dp[j] = dp[j] + dp[j-1] *pn[i];
    else if(j != 0) dp[j] = dp[j] *(1-pn[i]) +dp[j-1] *pn[i];
    else dp[j] = dp[j] *(1-pn[i]);
  }
  printf("%.10f\n",dp[tar]);
}