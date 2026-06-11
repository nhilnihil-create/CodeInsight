#include<bits/stdc++.h>
#define il inline
#define vd void
typedef unsigned long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
ll x[200010],s[200010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();ll X=gi();
	for(int i=1;i<=n;++i)x[i]=gi(),s[i]=s[i-1]+x[i];
	ll ans=9e18,res;
	for(int i=1;i<=n;++i){
		res=1ll*i*X+5*(s[n]-s[n-i]);
		int l=n-i-i,r=n-i;
		for(int j=5;r>0;j+=2,l-=i,r-=i)res+=1ll*j*(s[r]-s[std::max(0,l)]);
		ans=std::min(ans,res);
	}
	printf("%llu\n",ans+1ll*n*X);
	return 0;
}
