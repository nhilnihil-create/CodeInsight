#include<bits/stdc++.h>

using namespace std;

int main() {
	vector<int>dp;
	vector<int>arr;
	int val, n, j;

	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>val;
		arr.push_back(val);
	}

	dp.push_back(0);
	dp.push_back(abs(arr[0]-arr[1]));

	for(int i=2;i<n;i++) {
		dp.push_back(
			min(dp[i-2] + abs(arr[i]-arr[i-2]) , dp[i-1] + abs(arr[i]-arr[i-1])));
	}

	// for(auto x : dp) {
	// 	cout<<x<<" ";
	// }
	

	cout<<dp[n-1];

	return 0;
}