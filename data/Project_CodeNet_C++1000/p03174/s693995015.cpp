#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
typedef vector<vector<lli> > vvi;
typedef vector<ii> vii;
 
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
 
const int mod = 1e9 +7;
lli n, dp[4194304], a[21][21];
int solve(int man, int mask)
{
	if(man>=n) return 1;
	else if(dp[mask]!=-1)return dp[mask];
	else
	{
		lli ans=0;
		for(int i=0; i<n; i++)
			if(!((mask>>i)&1) && a[man][i]==1)
				ans=(ans+solve(man+1, mask^(1LL<<i)))%mod;
		return dp[mask]=ans;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=0; i<4194304; i++)dp[i]=-1;
	cin>>n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>a[i][j];
	cout<<solve(0,0);
}