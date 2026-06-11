#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int T;
ll a,b,c,d;
ll Gcd(ll x,ll y){return y?Gcd(y,x%y):x;}
bool check(ll a,ll b,ll c,ll d){
	if (a<b) return false;
	if (d<b) return false;
	ll gcd=Gcd(b,d),tmp=a%gcd,limit=c+1-b;
	if ((limit%gcd+gcd)%gcd>tmp) tmp+=gcd;
	return limit+(tmp-(limit%gcd+gcd)%gcd)>=0;
}

int main(){
#ifndef ONLINE_JUDGE
	//freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	for (int i=1;i<=T;++i){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (check(a,b,c,d)) printf("Yes\n");
		else printf("No\n");
	}
}
