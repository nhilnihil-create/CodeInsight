#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lb long double
using namespace std;
int s[20],ls;
inline ll get(){
	ll ans=0;
	for (int i=ls;i;--i) ans=ans*10ll+s[i];
	return ans;
}
inline void calc(ll x){
	ls=0;
	while (x) s[++ls]=x%10,x/=10;
}
inline int getsum(){
	int ans=0;
	for (int i=1;i<=ls;++i) ans+=s[i];
	return ans;
}
inline ll f(ll x){
	calc(x);
	lb mn=1e18;ll ans;
	for (int i=1;i<=ls;++i){
		for (;s[i]<=9;++s[i]){
			ll y=get();
			lb tmp=(lb)y/(lb)getsum();
			if (tmp<mn) mn=tmp,ans=y;
		}
		--s[i];
	}
	return ans;
}
int main(){
	int k;scanf("%d",&k);ll s=1;
	while (k--) printf("%lld\n",s),s=f(s+1);
	return 0;
}