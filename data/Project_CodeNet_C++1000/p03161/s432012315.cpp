#include<bits/stdc++.h>
using namespace std;

int solnB(int n,int k,vector<int>& arr){
	int dp[n];
	if(n<2) return 0;
	dp[n-1]=0;
	// dp[n-2]=abs(arr[n-1]-arr[n-2]);
	for(int i=n-2;i>=0;i--){
		dp[i]=INT_MAX;
		for(int j=1;j<=k&&i+j<n;j++)
			dp[i] = min(dp[i],abs(arr[i]-arr[i+j])+dp[i+j]);
	}
	return dp[0];
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<solnB(n,k,arr)<<endl;
}

/*
int solnA(int n,vector<int>& arr){
	int dp[n];
	if(n<2) return 0;
	dp[n-1]=0;
	dp[n-2]=abs(arr[n-1]-arr[n-2]);
	for(int i=n-3;i>=0;i--){
		dp[i] = min(abs(arr[i]-arr[i+1])+dp[i+1],abs(arr[i]-arr[i+2])+dp[i+2]);
	}
	return dp[0];
}
*/