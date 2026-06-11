#include<bits/stdc++.h>
using namespace std;
typedef long long 	ll;
const ll 	MOD		=  	1e+9+7;
const ll 	N 		= 	2*1e6;
int dp[10000001];
int arr[10000001];
int n,k;
int solve(int ind)
{
	if(ind==n-1)
	{
		return 0;
	}
	if(dp[ind]!=-1)
	{
		return dp[ind];
	}
	int ans=solve(ind+1)+abs(arr[ind+1]-arr[ind]);
	for(int i=1;i<=k;i++)
	{
		if(ind+i<n)
		{
			ans=min(ans,solve(ind+i)+abs(arr[ind+i]-arr[ind]));
		}
	}
	return dp[ind]=ans;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<solve(0)<<"\n";
	
	return 0;
}