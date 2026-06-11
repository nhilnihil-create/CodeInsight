#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (1e9)+7
int main( )
{
	ll n,k;cin>>n>>k;
	ll a[n],dp[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)dp[i]=INF;
	dp[0]=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<=i+k;j++){
			if(j<n) dp[j]=min(dp[j],abs(a[i]-a[j])+dp[i]);
		}
	}
	cout<<dp[n-1];
}