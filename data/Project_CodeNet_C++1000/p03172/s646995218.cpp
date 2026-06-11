// dp[x][y] = xth position and y candies, no. of ways
// dp[x][0] = 1

// dp[first][0] = dp[first][1] = ..... dp[first][a[0]] = 1

// dp[x][y] = dp[x-1][y] + dp[x-1][y-1] + dp[x-1][y-2] + ...
 				// ..... + dp[x-1][y-a[x]]
// dp[x-1] -> prefix_sum
// dp[x][y] = prefix_sum[y] - prefix_sum[y-a[x]-1]

// dp[last][k]
#include "bits/stdc++.h"
using namespace std;

const int M = 1e9 + 7;

int dp[100][100005];
int a[100];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i = 0;i < n; i++){
		cin>>a[i];
	}
	
	for(int i = 0; i <= a[0]; i++){
		dp[0][i] = 1;
	}
	
	for(int i = 1; i < n; i++){
		// dp[i]
		vector<int> prefix_sum(k+1);
		prefix_sum[0] = dp[i-1][0];
		for(int j = 1; j < k+1; j++){
			prefix_sum[j] = (prefix_sum[j-1] + dp[i-1][j]) % M;
		}
		for(int j = 0; j < k+1; j++){
			// dp[i][j]
			if(j > a[i])
				dp[i][j] = (prefix_sum[j] + M - prefix_sum[j-a[i]-1]) % M;
			else
				dp[i][j] = prefix_sum[j];
		}
		
	}
	cout << dp[n-1][k];
}
