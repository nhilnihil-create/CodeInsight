#include<bits/stdc++.h>
using namespace std;

int solnC(int n,vector<vector<int> > &arr){
	int dp[n][3];
	if(n<2) return max(arr[0][0],max(arr[0][1],arr[0][2]));
	dp[n-1][0]=arr[n-1][0];
	dp[n-1][1]=arr[n-1][1];
	dp[n-1][2]=arr[n-1][2];
	// dp[n-2]=abs(arr[n-1]-arr[n-2]);
	for(int i=n-2;i>=0;i--){
		for(int k=0;k<3;k++){
			int a=(k+1)%3,b=(k+2)%3;
			dp[i][k] = arr[i][k]+max(dp[i+1][a],dp[i+1][b]);
		}
		// cout<<dp[i][0]<<" "<<dp[0][1]<<" "<<dp[0][2]<<endl;
	}
	return max(dp[0][0],max(dp[0][1],dp[0][2]));
}
int main(){
	int n;
	cin>>n;
	vector<vector<int> > arr(n,vector<int>(3));
	for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	cout<<solnC(n,arr)<<endl;
}

/*
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