#include<bits/stdc++.h>
#define rep(i,s,t) for(register int i=s;i<=t;++i)
using namespace std;
const int N=1e6+11,mod=1e9+7;
int n,ans,a[N],inv[N];
int main(){
	cin>>n;
	rep(i,1,n)
		cin>>a[i];
	inv[1]=1;
	rep(i,2,n)
		inv[i]=mod-1ll*mod/i*inv[mod%i]%mod;
	rep(i,2,n)
		inv[i]=(inv[i]+inv[i-1])%mod;
	rep(i,1,n)
		ans=(ans+1ll*(inv[i]+inv[n-i+1]-1)*a[i])%mod;
	rep(i,1,n)
		ans=1ll*ans*i%mod;
	ans=(ans+mod)%mod;
	cout<<ans;}