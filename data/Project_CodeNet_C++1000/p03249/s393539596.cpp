#include<bits/stdc++.h>
typedef long long ll;
#define exp puts("-1"),exit(0);
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
ll D[100010];
int fa[100010],st[100010],siz[100010];
std::unordered_map<ll,int>M;
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)D[i]=gi(),st[i]=i,M[D[i]]=i,siz[i]=1;
	std::sort(st+1,st+n+1,[&](int a,int b){return D[a]<D[b];});
	ll ssiz=0;
	for(int _=n,i;_>1;--_){
		i=st[_];
		if(!(fa[i]=M[D[i]-n+2*siz[i]]))exp;
		siz[fa[i]]+=siz[i];ssiz+=siz[i];
	}
	if(D[st[1]]!=ssiz)exp;
	for(int i=1;i<=n;++i)if(fa[i])printf("%d %d\n",i,fa[i]);
	return 0;
}
