#include<bits/stdc++.h>
using namespace std;
long long dp[420][420], a[420], pref[420];

long long solve(int i, int j){
   if(i == j)
     return 0;
  
   long long &ans = dp[i][j];
   if(ans != -1)
     return ans;
   
   ans = 1e18;
   
   for(int k = i; k < j; k++){
     ans = min(ans, solve(i, k) + solve(k + 1, j) + pref[j] - pref[i - 1]);
   } 
   
   return ans;
}

int main(){
  int n; 
  cin >> n;
  
  for(int i = 1; i <= n; i++){
     cin >> a[i];
     pref[i] = pref[i - 1] + a[i];
  }
  
  memset(dp, -1, sizeof dp);
  cout << solve(1, n);
  
  return 0;
}
