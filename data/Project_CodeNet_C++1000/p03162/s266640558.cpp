#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n , a , b , c , dp[N][3];

int main(){

  cin >> n;

  cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

  for(int i = 1 ; i < n ; i++){
    cin >> a >> b >> c;
    dp[i][0] = a+max(dp[i-1][1],dp[i-1][2]);
    dp[i][1] = b+max(dp[i-1][0],dp[i-1][2]);
    dp[i][2] = c+max(dp[i-1][1],dp[i-1][0]);
  }

  cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << "\n";

}
