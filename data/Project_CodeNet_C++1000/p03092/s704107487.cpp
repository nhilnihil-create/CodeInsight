#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
ll f[2][5010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),R=gi(),L=gi();
	memset(f,63,sizeof f);
	f[0][0]=0;int t=0;
	for(int i=1,a;i<=n;++i){
		a=gi();memset(f[!t],63,sizeof f[!t]);
		for(int j=0;j<=n;++j){
			if(j<a)cnk(f[!t][a],f[t][j]),cnk(f[!t][j],f[t][j]+R);
			cnk(f[!t][std::max(j,a)],f[t][j]+L);
		}
		t^=1;
	}
	ll ans=9e18;for(int i=0;i<=n;++i)cnk(ans,f[t][i]);
	printf("%lld\n",ans);
	return 0;
}

