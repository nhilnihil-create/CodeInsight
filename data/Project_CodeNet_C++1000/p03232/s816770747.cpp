#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7,N=1e5+5;
int n,x;
ll fac[N],ans=0,res=1;
ll power(int a,int b)
{
	ll ans=1,p=a;
	while(b)
	{
		if(b&1)ans=ans*p%mod;
		p=p*p%mod;
		b>>=1;
	}
	return ans;
}
main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		fac[i]=(fac[i-1]+power(i,mod-2))%mod;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans=(ans+x*(fac[i]+fac[n-i+1]-1+mod)%mod)%mod;
		res=res*i%mod;
	}
	cout<<ans*res%mod<<endl;
}