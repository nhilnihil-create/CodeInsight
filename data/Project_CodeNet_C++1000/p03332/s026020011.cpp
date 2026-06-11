#include<iostream>
#define int long long
using namespace std;
const int N=3e5+5;
const int mod=998244353;
long long fact[N];
long long binpow(long long x,long long y){
	long long tich=1;
	while(y){
		if((y&1)){
			tich*=x;
			tich%=mod;
		}
		x=(x*x);
		x%=mod;
		y>>=1;
	}
	return tich;
}
long long C(int x,long long y){
	return ((fact[y]*binpow(fact[x],mod-2)%mod)*binpow(fact[y-x],mod-2))%mod;
}
signed main(){
	long long n,i,j,l,a,b,k;
	long long ans=0;
	cin>>n>>a>>b>>k;
	fact[0]=1;
	for(i=1;i<=n;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
	for(i=0;i<=min(n,k/a);i++){
		j=k-i*a;
		if(j%b!=0){
			continue;
		}
		j=j/b;
		if(j<=n){
			ans+=C(i,n)*C(j,n);
			ans%=mod;
		}
	}
	cout<<ans;
}