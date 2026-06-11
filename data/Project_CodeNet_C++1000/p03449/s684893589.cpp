#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long

int main()
{
	ll n;
	cin>>n;
	
	ll a[3][n+1];
	ll dp[3][n+1];
	
		for(int i=0;i<=2;i++){
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	}
	
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			dp[i][j]+=a[i][j];
		}
	}
	
		cout<<dp[2][n];
	
	
		
	
}


