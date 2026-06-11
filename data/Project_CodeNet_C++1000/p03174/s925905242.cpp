#include<bits/stdc++.h>
#define ll  int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define inf 100000000000000000LL
#define fast_io	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
using namespace std;
ll n;
ll dp[22][1<<22+1];
ll match(vector<vector<ll> > &mat,ll pos,ll d,ll flag)
{
//	cout<<"pos= "<<pos<<" "<<bitset< 5 >(flag).to_string()<<" "<<endl;
	if(mat[pos][d]==0)
	{
//		dp[pos][flag]=0;
		return 0;
	}
	if(pos==1)
	{
		return 1;
	}
	if(pos!=n+1&&dp[pos][flag]!=-1)
	{
//			cout<<"xxpos= "<<pos<<" "<<"i= null "<<" "<<bitset< 5 >(flag).to_string()<<" "<<dp[pos][flag]<<endl;
		return dp[pos][flag];
	}
	ll s=0;

	for(ll i=1;i<=n;i++)
	{

		if(((1<<i)&flag)==0)
		{
			ll f=flag|(1<<i);
			ll x=match(mat,pos-1,i,f);
			s=(s%mod+x%mod)%mod;
//			cout<<"pos= "<<pos-1<<" "<<"i= "<<i<<" "<<bitset< 5 >(f).to_string()<<" "<<x<<endl;
		}
		
	}
	
	dp[pos][flag]=s;
	
	return dp[pos][flag];
	
}
int main()
{
	memset(dp,-1,sizeof(dp));
	fast_io;
	cin>>n;
	vector<vector<ll> > mat(n+2,vector<ll>(n+2,0));
	
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			cin>>mat[i][j];
		}
	}
	
//	for(ll i=1;i<=n;i++)
//	{
//		for(ll j=1;j<=n;j++)
//		{
//			cout<<dp[i][j]<<"\t";
//		}
//		cout<<endl;
//	}
	mat[n+1][n+1]=1;
	cout<<match(mat,n+1,n+1,0LL)<<endl;
//	for(ll i=0;i<=16;i++)
//	{
//		cout<<i<<" "<<bitset< 5 >(i).to_string()<<"\n\n";
//		for(ll j=1;j<=n;j++)
//		{
//			cout<<dp[j][i]<<"\t";
//		}
//		cout<<endl;
//	}
	
}