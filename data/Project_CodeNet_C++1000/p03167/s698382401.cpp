#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
int main()
{
	vector<string> v;
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<n;i++)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	
	ll dp[n][m];
	dp[0][0]=0;
	ll j=0;
	while(j+1<m && v[0][j+1]=='.')
	{
		dp[0][j+1]=1;
		j++;
	}
	j++;
	while(j<m)
	{
		
		dp[0][j]=0;
		j++;
	}
	
	ll i=0;
	while(i+1<n && v[i+1][0]=='.')
	{
		dp[i+1][0]=1;
		i++;
	}
	i++;
	while(i<n)
	{
		dp[i][0]=0;
		i++;
	}
	
	
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<m;j++)
		{
			if(v[i][j]=='#')
			dp[i][j]=0;
			else
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
		}
	}
	

	cout<<dp[n-1][m-1];
	
	
}
