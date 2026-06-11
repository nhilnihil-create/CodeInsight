#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
	    cin>>arr[i];
	}
	
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for(int i = 1; i < n; i++){
	    
	    for(int j = 1; i-j >= 0 && j<=k; j++){
	        dp[i] = min(abs(arr[i] - arr[i-j]) + dp[i-j], dp[i]);
	    }
	}
	cout<<dp[n-1];
	return 0;
}
