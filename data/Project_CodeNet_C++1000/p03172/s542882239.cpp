#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define inf 100000000000000000LL
#define fast_io	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
using namespace std;
ll dp[100+1][100000+1];
ll S[100+1][100000+1];
ll n,k;
int main()
{
	cin>>n>>k;
	
	ll A[n+1];
	
	for(ll i=1;i<=n;i++)
	cin>>A[i];
	
//	memset(dp,0,sizeof(dp));
	
	
	S[1][0]=dp[1][0]=1;	
	
	for(ll j=1;j<=k;j++)	
	{
		if(j<=A[1])
		dp[1][j]=1;
		S[1][j]=(S[1][j-1]%mod+dp[1][j]%mod)%mod;
		
//		cout<<S[0][j]<<" ";
	}
//	cout<<"\n\n";
	for(ll i=2;i<=n;i++)
	{
		S[i][0]=dp[i-1][0];
		dp[i][0]=dp[i-1][0];
		for(ll j=1;j<=k;j++)
		{

			
			dp[i][j]=(S[i-1][j]%mod-((j-A[i]-1>=0)?S[i-1][j-A[i]-1]:0LL)%mod+mod)%mod;

			S[i][j]=(S[i][j-1]%mod+dp[i][j]%mod)%mod;
//			cout<<dp[i][j]<<" ";
		}
//		cout<<endl;
	}
	cout<<dp[n][k]<<endl;
}