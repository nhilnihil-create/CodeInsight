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
LL a[maxn],deg[maxn],mark[maxn],ans[maxn];
std::vector<LL> V[100009];
std::queue<LL> que;
int main(){
    n=Read();
    for(LL i=1;i<n;++i){
    	LL x(Read()),y(Read());
    	V[x].pb(y); V[y].pb(x);
    	deg[x]++; deg[y]++;
	}
	for(LL i=1;i<=n;++i){
		a[i]=Read();
	}
	std::sort(a+1,a+1+n);
	LL sum(0);
	for(LL i=1;i<n;++i){
		sum+=a[i];
	}
	printf("%lld\n",sum);
	for(LL i=1;i<=n;++i){
		if(deg[i]==1) que.push(i),mark[i]=1;
	}
	for(LL i=1;i<=n;++i){
		LL x(que.front()); que.pop();
		ans[x]=a[i];
		for(LL k=0;k<V[x].size();++k){
			LL v(V[x][k]); if(mark[v]) continue;
			deg[v]--;
			if(deg[v]==1){
				mark[v]=1;
				que.push(v);
			}
		}
	}
	for(LL i=1;i<=n;++i) printf("%lld ",ans[i]);
	puts("");
	return 0;
}

