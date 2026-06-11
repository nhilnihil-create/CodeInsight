#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
#define pi 3.1415926535897
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define mod1 998244353
#define inf 1000000000000000000
#define inf1 1000000000
#define endl '\n'
ll dp[3005][3005];
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n;
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
	dp[1][1]=1;
	for(ll i=1;i<n;i++)
	{
		for(ll j=1;j<=i;j++)
		{
			if(s[i-1]=='<')
				dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
			else
			{
				dp[i+1][1]=(dp[i+1][1]+dp[i][j])%mod;
				dp[i+1][j+1]=(dp[i+1][j+1]+mod-dp[i][j])%mod;
			}
		}
		for(ll j=1;j<=i;j++)
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i+1][j])%mod;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++)
		ans=(ans+dp[n][i])%mod;
	cout<<ans<<endl;
	return 0;
}