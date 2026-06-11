#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long int ll;
 
int main() {
    int n;
    cin>>n;
    double prob[n];
  	for(int i=0; i<n; i++){
      cin>>prob[i];
    }
    
    double dp[n+1][n+1];
    memset(dp, 0.0, sizeof(dp));
    dp[0][0] = 1.0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(j==0){
                dp[i][j] = (1-prob[i-1]) * dp[i-1][j];
            }
            else{
                dp[i][j] = (1-prob[i-1]) * dp[i-1][j] + prob[i-1] * dp[i-1][j-1];
            }
        }
    }
  	double ans = 0.0;
  	for(int j=(n+1)/2; j<=n; j++){
    	ans += dp[n][j];
    }
    cout << fixed << setprecision(12) << ans;
}