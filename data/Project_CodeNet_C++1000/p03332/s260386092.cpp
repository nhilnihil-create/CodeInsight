#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll p=998244353;
ll n,a,b,k,ans,fct[300005]={1};
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)
			res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
ll C(ll n,ll m){
	return fct[n]*qpow(fct[n-m]*fct[m]%p,p-2)%p;
}
int main(){
	ios::sync_with_stdio(false);
	ll i,j;
	cin>>n>>a>>b>>k;
	for(i=1;i<=n;i++)
		fct[i]=fct[i-1]*i%p;
	for(i=0;i<=n;i++){//num of a
		j=k-i*a;
		if(j%b!=0||j<0)
			continue;
		j=j/b;
		if(j>n)
			continue;
		ans=(ans+C(n,i)*C(n,j))%p;
	}
	cout<<ans;
	return 0;
}