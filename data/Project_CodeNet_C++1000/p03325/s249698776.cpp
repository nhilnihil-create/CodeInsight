#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


ll div_2(ll x)
{
	ll ret=0;
	while(x%2==0)
	{
		x/=2;
		ret++;
	}
	return ret;
}
int main()
{
	int N;
	cin>>N;
	ll ans=0;
	rep(i,N)
	{
		ll a;
		cin>>a;
		ans+=div_2(a);
	}
	cout<<ans<<endl;
	return 0;
}
