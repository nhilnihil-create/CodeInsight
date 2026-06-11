#include <bits/stdc++.h>
using namespace std;
int jump(int *h,int i,int n,int *dp){
	if(i>=n-1)return dp[i] = 0;
	if(i == n-2)return dp[i] = abs(h[n-1] - h[i]);
	if(dp[i]!= -1)return dp[i];
	return dp[i] = min(abs(h[i+1] - h[i]) + jump(h,i+1,n,dp),abs(h[i+2] - h[i]) + jump(h,i+2,n,dp));
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int *h = new int[n];
	int *dp = new int[n];
	for(int i = 0;i<n;i++)
		cin>>h[i];
	for(int i = 0;i<n;i++)
		dp[i] = -1;
	cout<<jump(h,0,n,dp)<<endl;
	return 0;
}