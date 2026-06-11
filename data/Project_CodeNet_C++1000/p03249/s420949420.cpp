#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<map>
#define LL long long
#define M 200020
using namespace std;
LL read(){
	LL nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,D[M],sz[M],now,cur,u[M],v[M],tmp,tar;
LL fs[M],nt[M<<1],to[M<<1],F[M],G[M],mx[M];
map<LL,LL>K;
void fad(){puts("-1");exit(0);}
struct node{LL id,dst;}p[M];
bool cmp(node x,node y){return x.dst<y.dst;}
void e(LL x,LL y){cur++,u[cur]=x,v[cur]=y;}
void link(LL x,LL y){nt[tmp]=fs[x],fs[x]=tmp,to[tmp++]=y;}
void dfs1(LL x){
	for(LL i=fs[x];i!=-1;i=nt[i]){
//		printf("%lld   --> %lld\n",x,to[i]);
		dfs1(to[i]),F[x]+=F[to[i]]+sz[to[i]];
	}
}
void dfs2(LL x){
	for(LL i=fs[x];i!=-1;i=nt[i]){
		G[to[i]]=G[x]-sz[to[i]]-sz[to[i]]+n,dfs2(to[i]);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),memset(fs,-1,sizeof(fs));
	for(LL i=1;i<=n;i++) p[i].id=i,D[i]=read(),p[i].dst=D[i],K[D[i]]=i;
	sort(p+1,p+n+1,cmp);
//	for(LL i=1;i<=n;i++) printf("%lld  %lld\n",p[i].id,p[i].dst);
	for(LL i=n;i>1;i--){
		sz[p[i].id]++;
		LL num=p[i].dst-n+sz[p[i].id]*2ll;
		if(K.count(num)){
//			printf("%lld\n",num);
			m=K[num];
			sz[m]+=sz[p[i].id];
			link(m,p[i].id);
			e(m,p[i].id);
		}
		else fad();
	}
	if(sz[p[1].id]!=n-1) fad();
//	puts("S");
	dfs1(p[1].id),G[p[1].id]=F[p[1].id],dfs2(p[1].id);
	for(LL i=1;i<=n;i++) if(G[i]!=D[i]) fad();
	for(LL i=1;i<n;i++) printf("%lld %lld\n",u[i],v[i]); 
	return 0;
}