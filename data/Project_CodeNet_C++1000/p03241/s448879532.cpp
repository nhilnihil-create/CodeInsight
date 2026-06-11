#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


vector<ll> divisor(ll x)
{
	vector<ll> ret;
	for(ll i=1;i<=(ll)sqrt(x);i++)
	{
		if(x%i==0)
		{
			ret.push_back(i);
			if(x/i!=i) ret.push_back(x/i);
		}
	}
	return ret;
}
int main()
{
	ll N,M;
	cin>>N>>M;
	vector<ll> divs=divisor(M);
	sort(divs.begin(),divs.end());
	ll ans=0;
	for(ll x : divs)
	{
		if(x*N<=M) ans=x;
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
