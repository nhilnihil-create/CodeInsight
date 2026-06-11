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
ll arr[16][16];
ll val[1<<16];
ll dp[1<<16];
int main()
{
	fastio;
	#ifdef APNA_IO
		freopen("input.txt" , "rt" ,stdin);
		freopen("output.txt" , "wt" ,stdout);
	#endif
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin>>arr[i][j];
	for(ll i=1;i<(1<<n);i++)
	{
		ll k=log2(i&(-i));
		val[i]=val[i&(~(1<<k))];
		for(ll j=0;j<n;j++)
			if((i&(1<<j))!=0)
				val[i]+=arr[j][k];
	}
	for(ll i=1;i<(1<<n);i++)
	{
		for(ll j=i;j>0;j=(j-1)&i)
		{
			ll k=(i&(~j));
			dp[i]=max(dp[i],dp[k]+val[j]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}