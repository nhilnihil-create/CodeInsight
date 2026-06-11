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
pair<ll,pair<ll,ll>> arr[1005];
ll dp[1005][20005];
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		arr[i]=mp(a+b,mp(b,c));
	}
	sort(arr+1,arr+n+1);
	ll ma=arr[n].ff;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=ma;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=arr[i].ff-arr[i].ss.ff && j-arr[i].ff<=0)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-arr[i].ff+arr[i].ss.ff]+arr[i].ss.ss);
			}	
		}
	}
	ll ans=0;
	for(ll i=1;i<=ma;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}