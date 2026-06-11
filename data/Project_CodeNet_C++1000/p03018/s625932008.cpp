#include<bits/stdc++.h>
typedef long long LL;
typedef double dl;
#define opt operator
#define pb push_back
const LL maxn=1e6+9,mod=998244353,inf=0x3f3f3f3f;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3ll)+(x<<1ll)+c-'0'; c=getchar();
	}return x*f;
}
void Chkmin(LL &x,LL y){
	if(y<x) x=y;
}
void Chkmax(LL &x,LL y){
	if(y>x) x=y;
}
LL add(LL x,LL y){
	return x+=y,x>=mod?x-mod:x;
}
LL dec(LL x,LL y){
	return x-=y,x<0?x+mod:x;
}
LL mul(LL x,LL y){
	return 1ll*x*y%mod;
}
LL n;
LL f[maxn];
char s[maxn];
int main(){
    scanf(" %s",s+1);
    n=strlen(s+1);
    for(LL i=n-2;i>=0;--i){
    	if(s[i+1]=='B' && s[i+2]=='C') f[i]=f[i+2]+1;
    	if(s[i+1]=='A') f[i]=f[i+1];
	}
	LL ret(0);
	for(LL i=0;i<=n-2;++i) if(s[i]=='A') ret+=f[i];
	printf("%lld\n",ret);
	return 0;
}

