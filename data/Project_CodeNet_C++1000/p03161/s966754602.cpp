// frogs.cpp
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int main(){

int n,k;
cin >>n>>k;
int arr[n];
for(int i=0;i<n;i++) cin>> arr[i];
int dp[n];
memset(dp,0,sizeof(dp));
dp[0] = 0;
int ans = 0;

// cout << dp[0] << " ";
for(int i = 1;i<n;i++){
	dp[i] = INT_MAX;
	for(int j=1;j<=k;j++){

	// cout << "i "<<i <<endl;
	if(i-j >=0)
	dp[i] =  min(abs(arr[i-j]  - arr[i]) + dp[i-j], dp[i] );
	// else{
	// 	dp[i] = abs(arr[i-1] - arr[i]) + dp[i-1];
	// }
}
	// ans +=dp[i];

	// cout << dp[i] << " ";
}
// cout << endl;

cout << dp[n-1]<< endl;



return 0;
}