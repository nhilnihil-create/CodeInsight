#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define inf 1000000000000000000
#define ff first
#define ss second
#define Clear(x) memset(x,0,sizeof(x))
#define all(x) (x).begin(),(x).end()

void checkpoint1()
{
	/******think more code less******/
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

bool comp(pair< ll,ll > &a,pair< ll,ll > &b)
{
	if(a.ff!=b.ff)
		return a.ff<b.ff;
	else
	{
		if(a.ss>b.ss)
			return b.ss<a.ss;
		else if(a.ss<b.ss)
			return a.ss<b.ss;
	}
	return a.ff>b.ff;
}

ll powe(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1)
		{
			res*=a;
			res%=mod;
		}
		a*=a;
		a%=mod;
		b>>=1;
	}
	return res;
}
int main()
{
	checkpoint1();
	ll n;
	cin>>n;
	ld dp[n+1][n+1];
	ld p[n+1];
	for(ll i=1;i<=n;i++)
		cin>>p[i];
	dp[0][0]=1.000;
	dp[1][0]=1-p[1];
	for(ll i=2;i<=n;i++)
		dp[i][0]=dp[i-1][0]*(1-p[i]);
	for(ll i=1;i<=n;i++)
		dp[i][i]=p[i]*dp[i-1][i-1];
	for(ll i=2;i<=n;i++)
	{
		for(ll j=1;j<i;j++)
			dp[i][j]=dp[i-1][j]*(1-p[i])+p[i]*dp[i-1][j-1];
	}
	ld ans=0.000000;
	for(ll i=n/2+1;i<=n;i++)
		ans+=dp[n][i];
	cout<<fixed<<setprecision(10)<<ans;
	return 0;
}