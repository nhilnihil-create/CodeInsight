#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
const int N=17;
ll a[20][20],n;
ll dp[1<<N],dp2[1<<N];
int _runtimeTerror_()
{
	mem1(dp);
	ll i,j,k,l;
	cin>>n;
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<n;++j)
			cin>>a[i][j];
	}
	ll sub=(1<<n);
	for(i=1;i<sub;++i)
	{
		dp2[i]=0;
		vector<ll> v;
		for(j=n-1;j>=0;--j)
			if(i&(1<<j))
				v.pb(j);
		ll ss=sz(v);
		for(ll k=0;k<ss;++k)
		{
			for(ll l=k;l<ss;++l)
				dp2[i]+=a[v[k]][v[l]];
		}
	}
	dp[0]=0;
	for(i=1;i<sub;++i)
	{
		for(j=n-1;j>=0;--j)
		{
			if(i&(1<<j))
				break;
		}
		dp[i]=dp[i&(~(1<<j))];
		vector<ll> v;
		for(k=j-1;k>=0;--k)
			if(i&(1<<k))
				v.pb(k);
		ll x=(1<<sz(v));
		for(l=1;l<x;++l)
		{
			ll num=0,val=0,ff=0;
			ff+=1<<j;
			for(k=0;k<sz(v);++k)
			{
				if(l&(1<<k))
				{
					ff+=1<<v[k];
				}
				else
					num+=1<<v[k];
			}
			amax(dp[i],dp[num]+dp2[ff]);
		}
	}
	//cout<<dp[5]<<endl;
	cout<<dp[sub-1]<<endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifdef runSieve
		sieve();
	#endif
	#ifdef NCR
		initialize();
	#endif
	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	cerr<<"\n"<<_time_;
	return 0;
}
