#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const int M=(1<<19);
int a[M];
int dp[M][2];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<(1<<n);i++)
	{
		cin>>a[i];
		dp[i][0]=a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int mask=0;mask<(1<<n);mask++)
		{
			if((mask&(1<<i)))
			{
				vector<int> vt;
				vt.pb(dp[mask][0]);
				vt.pb(dp[mask][1]);
				vt.pb(dp[(mask^(1<<i))][0]);
				vt.pb(dp[(mask^(1<<i))][1]);
				sort(all(vt));
				reverse(all(vt));
				dp[mask][0]=vt[0];
				dp[mask][1]=vt[1];
			}
		}
	}
	for(int i=1;i<(1<<n);i++)
	{
		int res=0;
		int mask=0;
		for(int j=n-1;j>=0;j--)
		{
			if((i&(1<<j))==0)
				continue;
			int nm = (mask^((1<<j)-1));
			res=max(res,dp[nm][0]+dp[nm][1]);
			mask = (mask^(1<<j));
		}
		res=max(res,dp[mask][0]+dp[mask][1]);
		cout<<res<<"\n";
	}
	return 0;
}