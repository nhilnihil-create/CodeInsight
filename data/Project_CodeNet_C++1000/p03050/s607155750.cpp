#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


vector<ll> divisor(ll N)
{
	vector<ll> ret;
	for(ll i=1;i<=(ll)sqrt(N);i++)
	{
		if(N%i==0)
		{
			if(N/i!=i) ret.push_back(i);
		}
	}
	return ret;
}
/*
 * N/m=N%m
 * r=N%m
 * N=x*m+r
 * r=x
 * N=r*m+r
 * N=r*(m+1)
 * m+1=N/r
 * m=N/r-1
 */
int main()
{
	ll N;
	cin>>N;
	vector<ll> divs=divisor(N);
	ll ans=0;
	for(ll x : divs)
	{
		ll m=N/x-1;
		if(N/m==N%m) ans+=m;	
	}
	cout<<ans<<endl;
	return 0;
}
