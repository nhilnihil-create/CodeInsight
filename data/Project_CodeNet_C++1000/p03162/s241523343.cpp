#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int vacation(int arr[][3],int n){
	int dp[n][3];
	dp[0][0]=arr[0][0];
	dp[0][1]=arr[0][1];
	dp[0][2]=arr[0][2];
	for (int i=1;i<n;i++){
		dp[i][0]=arr[i][0]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=arr[i][1]+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=arr[i][2]+max(dp[i-1][1],dp[i-1][0]);
	}
	return max(max(dp[n-1][0],dp[n-1][1]),dp[n-1][2]);
}




int main(){
	int n;
	cin>>n;
	int arr[n][3];
	for (int i=0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[i][0]=a;
		arr[i][1]=b;
		arr[i][2]=c;
	}
	cout<<vacation(arr,n);
	return 0;
}

