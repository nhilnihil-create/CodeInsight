#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int sqr(int x){return x*x%mod;}
int pow(int a,int n){return n?sqr(pow(a,n/2))*(n&1?a:1)%mod:1;}
int n,x,h[200001],ans=0,r=1;
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)h[i]=(h[i-1]+pow(i,mod-2))%mod;
	for(int i=1;i<=n;i++)cin>>x,ans+=x*(h[i]+h[n-i+1]-1+mod)%mod,r=r*i%mod;
	cout<<ans%mod*r%mod<<endl;
}
