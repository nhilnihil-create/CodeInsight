#include <bits/stdc++.h>
#define ll long long int

using namespace std;
int main(){
	
	ll n;
	cin>>n;
	ll A[n];
	int k;
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	ll dp[n+5];
//	memset(dp,INT_M)
	dp[0]=0;
	dp[1]=abs(A[1]-A[0]);
	
	for(int i=2;i<n;i++){
		dp[i]=INT_MAX;
		for(int j=1;j<=k&&i-j>=0;j++){
			
			dp[i]=min(dp[i],dp[i-j]+abs(A[i]-A[i-j]));
		}
	}
	cout<<dp[n-1];
	return 0;
	
	
	
}
