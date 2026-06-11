#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18  

int main() {
  int n; cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll dp[n][n];
  ll sum[n];
  sum[0] = arr[0];
  for(int i = 1; i < n; i++) {
  	sum[i] = sum[i - 1] + arr[i];
  }
  for(int i = n - 1; i >= 0; i--) {
	for(int j = i; j < n; j++) {
    	if(i == j) dp[i][j] = 0;
      	else {
        	dp[i][j] = INF;
          	for(int p = i; p < j; p++) {
                ll left = (i - 1) >= 0 ? sum[i - 1] : 0;
                ll right = sum[j];
                ll temp = right - left;
                dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j] + temp);
            }
		}
    }
  }
  cout << dp[0][n - 1] << endl;
}