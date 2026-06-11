#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld double
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define setpr(pp) fixed<<setprecision(pp)
#define FOR(I,N) for(I=0;I<N;++I)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod	%1000000007
#define pi 3.141592653
#define MX 1000000007

ll n;
ll dp[5000000];
bool a[22][22];

ll cnt(ll mask)
{
	ll ans=0;
	for(int i=0;i<n;++i)
	{
		if(mask&1<<i)
			ans++;
	}
	return ans;
}

int main()
{
	MS0(dp);
	cin>>n;
	ll i,j;
	FOR(i,n)
	{
		FOR(j,n)
		{
			cin>>a[i][j];
		}
	}
	dp[0]=1;
	ll k,N = 1<<n;
	for(j=0;j<N-1;++j)
	{
		k = cnt(j);
		for(i=0;i<n;++i)
		{
			if((j&1<<i) == 0 && a[k][i]==1)
				dp[j|1<<i] = (dp[j|1<<i] + dp[j])mod;
		}
	}
	cout<<dp[N-1];
}