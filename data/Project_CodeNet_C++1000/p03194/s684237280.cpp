#include<iostream>
#include<cstdio>
#include<cmath>
#define rg register
#define ll long long

using namespace std;
ll n,p,k,ans=1LL;
int cnt;

inline ll quick_pow(ll a,ll b)
{
	ll sum=1LL;
	while(b)
	{
		if(b&1) sum*=a;
		a*=a;
		b>>=1;
	}
	return sum;
}
int main()
{
	scanf("%lld%lld",&n,&p);
	if(n==1LL || p==1LL)
	{
		cout<<p<<endl;
		return 0;
	}
	k=(ll)(sqrt(p));
	for(ll i=2;i<=k;i++)
	{
		if(p%i==0LL)
		{
			cnt=1;
			p/=i;
			while(p%i==0LL)
			{
				p/=i;
				cnt++;
			}
//			cout<<cnt<<endl;
			if((ll)cnt>=n) ans*=quick_pow(i,(ll)cnt/n);
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
