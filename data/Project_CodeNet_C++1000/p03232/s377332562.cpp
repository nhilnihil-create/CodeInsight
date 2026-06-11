#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1000000007;
int n,m;
ll a[N],s[N];
ll fac[N],inv[N];
ll po(ll x,ll k){
	if(!k) return 1;
	ll s=po(x,k>>1);s=s*s%mod;
	if(k&1) return s*x%mod;
	return s; 
}
ll s0[N],s1[N];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]+a[i])%mod;
	}
	fac[0]=1;
	for(i=1;i<N;i++) fac[i]=(fac[i-1]*i)%mod;
	inv[N-1]=po(fac[N-1],mod-2);
	for(i=N-2;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(i=1;i<=n;i++)
		s0[i]=(s0[i-1]+a[i]*i)%mod;
	for(i=n;i;i--)
		s1[i]=(s1[i+1]+a[i]*(n-i+1))%mod;
	ll ans=0;
	for(i=1;i<n;i++){
		int k=min(i,n-i+1);
		ll tmp=((s0[k]+s1[n-k+1]+(s[n-k]-s[k]+mod)*k-s[i]-(s[n]-s[n-i]))%mod+mod)%mod;
		if(i+2<=n) ans=(ans+((tmp*inv[i+2]%mod)*2*fac[i]%mod)*fac[n])%mod;
		ans=(ans+((s[i]*inv[i+1]%mod)*fac[i]%mod)*fac[n])%mod;
		ans=(ans+(((s[n]-s[n-i]+mod)*inv[i+1]%mod)*fac[i]%mod)*fac[n])%mod;
	}
	ans=(ans+s[n]*fac[n]%mod)%mod;
	cout<<ans;
	return 0;
}
