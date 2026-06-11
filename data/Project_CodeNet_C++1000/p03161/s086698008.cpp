#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, k;
	cin >> n >> k;
	int arr[n];
	int dp[n+1];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		dp[i+1] = INT_MAX;
	}
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j <= i+k; j++){
			if(j < n){
				dp[j] = min(dp[j], dp[i]+abs(arr[j]-arr[i]));
			}
		}
	}
	cout << dp[n-1] << "\n";
	return 0;
}