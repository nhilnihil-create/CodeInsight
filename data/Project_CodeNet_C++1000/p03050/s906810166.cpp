#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,ans;
void check(ll x){
	if(!x)return;
	ans+=(n==n/x*(x+1)?x:0);
}
int main(){
	n=read();
	for(ll i=1;i*i<=n;++i){
		if(n%i==0){
			check(i-1);
			if(i*i!=n)check(n/i-1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}


