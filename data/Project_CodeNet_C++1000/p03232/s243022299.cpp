#include "bits/stdc++.h"
using namespace std;

#define pb  push_back
#define mp  make_pair
#define ll  long long
#define itr iterator

typedef pair<ll,ll> pii;

const ll MAX=2e5+9;
const ll INF=1e12;
const ll mod=1e9+7;

ll N,res,arr[MAX],dp[MAX],fact[MAX],ifact[MAX];

ll power(ll base,ll exp)
{
	ll res=1;
	while(exp)
	{
		if(exp%2)
			res*=base;
		base*=base;
		res%=mod;
		base%=mod;
		exp/=2;
	}
	return res;
}

ll nCr(ll N,ll K)
{
	return ((fact[N]*ifact[K])%mod*ifact[N-K])%mod;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	fact[0]=1;
	ifact[0]=1;
	for(ll A=1;A<MAX;A++)
	{
		fact[A]=(A*fact[A-1])%mod;
		ifact[A]=power(fact[A],mod-2);
	}
	cin>>N;
	for(int A=1;A<=N;A++)	
		cin>>arr[A];
	for(int A=2;A<=N;A++)
	{
		dp[A]=((nCr(N,A)*fact[A-1])%mod*fact[N-A])%mod;
		dp[A]=(dp[A-1]+dp[A])%mod;
	}
	for(int A=1;A<=N;A++)
	{
		res=(res+(arr[A]*fact[N])%mod)%mod;
		res=(res+(arr[A]*dp[N-A+1])%mod)%mod;
		res=(res+(arr[A]*dp[A])%mod)%mod;
	}
	cout<<res;
	return 0;
}