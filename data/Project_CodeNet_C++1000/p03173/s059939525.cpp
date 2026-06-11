/* Author : fenwick123 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> pref (n , 0);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    pref[i] = a[i];
    if (i > 0) pref[i] += pref[i - 1];
  } 
  const long long inf = (long long) 2e18;
  vector<vector<long long>> dp (n + 1 , vector<long long> (n + 1 , inf));
  for (int i = n - 1; i >= 0; --i){
    for (int j = i; j < n; j++){
      if (j == i){
        dp[i][j] = 0;
        continue;
      } 
      for (int k = i; k < j; k++){
        long long cost = pref[j] - (i - 1 >= 0 ? pref[i - 1] : 0);
        dp[i][j] = min (dp[i][j] , dp[i][k] + dp[k + 1][j] + cost);
      }
    }
  }
  cout << dp[0][n - 1] << endl; 
  return 0;
}