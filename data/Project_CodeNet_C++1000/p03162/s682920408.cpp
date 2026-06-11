// vacations.cpp
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;


int main(){
	int n;
	cin >> n;

	if(n==0) return 0;
	int dp[n][3];
	memset(dp,0,sizeof(dp));
	int a,b,c;
	int arr[n][3];
	for(int i=0;i<n;i++){
		cin >> a>>b>>c;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for(int i=1;i<n;i++){
		dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + arr[i][0];
		dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + arr[i][1];
		dp[i][2] = max(dp[i-1][1],dp[i-1][0]) + arr[i][2];
	}
	
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));




	return 0;
}