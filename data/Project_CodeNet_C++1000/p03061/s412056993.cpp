#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int gcd(int a, int b){return b? gcd(b,a%b):a;}

int main(){
  int n;
  cin >> n;
  int dp[n][3];
  for(int i=0; i<n; ++i){
    int a;
    cin >> a;
    if(i==0){
      dp[0][0] = a;
      dp[0][1] = 0;
      dp[0][2] = 0;
      continue;
    }
    dp[i][0] = gcd(a,dp[i-1][0]);
    dp[i][1] = max(gcd(a,dp[i-1][2]),gcd(a,dp[i-1][1]));
    dp[i][2] = dp[i-1][0];
  }
  cout << max(dp[n-1][1], dp[n-1][2]) << endl;
}