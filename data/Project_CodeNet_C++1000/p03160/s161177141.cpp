#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int dp[n+1];
	dp[0]=0;
	dp[1]=abs(arr[0]-arr[1]);
	for(int i=2;i<n;i++){
	    dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
	}
	cout<<dp[n-1];
	return 0;
}