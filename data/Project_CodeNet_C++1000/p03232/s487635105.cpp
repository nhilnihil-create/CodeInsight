#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
#define Mod 1000000007
using namespace std;
inline ll read(){
	ll x=0,c;while(!isdigit(c=getchar()));
	while(x=x*10+c-'0',isdigit(c=getchar()));
	return x;
}
ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res=1ll*res*x%Mod;
		x=1ll*x*x%Mod;y>>=1;
	}return res;
}
ll a[maxn],n,fac[maxn],inv[maxn];
inline void init(){
	fac[0]=1;
	for(ll i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%Mod;
	for(ll i=1;i<=n;i++)inv[i]=(inv[i-1]+ksm(i,Mod-2))%Mod;
}
int main(){
	n=read();init();
	for(ll i=1;i<=n;i++)a[i]=read();
	ll ans=0;
	for(ll i=1;i<=n;i++)ans=(ans+a[i]*(inv[i]+inv[n-i+1]-1)%Mod)%Mod;
	printf("%d\n",ans*fac[n]%Mod);return 0;
}