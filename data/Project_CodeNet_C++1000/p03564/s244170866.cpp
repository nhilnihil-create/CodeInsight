#include<bits/stdc++.h>
#define ll long long
#define nes ios_base :: sync_with_stdio(0); cin.tie(0);
using namespace std;
int main(){
	nes;
	ll n,k;
	cin>>n>>k;
	ll dp[n+1]={0};
	dp[0]=1;
	for(int i=1;i<=n;++i) dp[i]=min(dp[i-1]*2,dp[i-1]+k);
	cout<<dp[n];
	return 0;
}
