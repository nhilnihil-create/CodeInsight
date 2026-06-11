#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline LL read(){
	LL x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL MAXN = 500010;
const LL INF = 1e18;

LL N,X;
LL ans=INF,ret=0;
LL s[MAXN+1],a[MAXN+1];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(),X=read();
	for(LL i=1;i<=N;i++) a[i]=read(),s[i]=s[i-1]+a[i];
	for(LL i=1;i<=N;i++){
		LL now=0; ret=0;
		for(LL j=N;j>=1;j-=i){
			LL r=j,l=max(j-i+1,1LL); ++now;
			ret+=(s[r]-s[l-1])*(2*now+1); 
			if(ret>ans) {ret=ans; break;}
			if(now==1) {
				ret+=(s[r]-s[l-1])*2;
				if(ret>ans) {ret=ans; break;}
				ret+=(r-l+1)*X;
			}
			if(ret>ans) {ret=ans; break;}
		} ans=min(ans,ret);
	} printf("%lld\n",ans+N*X);
	return 0;
}


