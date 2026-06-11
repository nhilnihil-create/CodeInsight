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
const LL MAXN = 100010;
const LL INF = 2147483600;

LL N;
struct dat{
	LL l,r,pos,id;
}f[2][MAXN+1]; LL nw[2];
bool cmpl(dat a,dat b){
	return a.l>b.l;
}
bool cmpr(dat a,dat b){
	return a.r<b.r;
}
inline bool Inc(dat a,LL x){
	return a.l<=x&&a.r>=x;
}
inline bool Find(LL x,LL y,LL z){
	if(y<z) return x; else return (x^1);
}
bool vis[MAXN+1];
inline LL solve(LL x){
	nw[0]=nw[1]=1; LL ans=0,last=0;
	for(LL i=1;i<=N;i++) vis[i]=0;
	for(LL i=1;i<=N;i++){
		while(nw[x]<=N&&(vis[f[x][nw[x]].id]||!Find(x,last,f[x][nw[x]].pos))) ++nw[x];
		if(nw[x]>N) {ans+=abs(last); return ans;}
		vis[f[x][nw[x]].id]=1; 
		if(Inc(f[x][nw[x]],last)) continue;
		ans+=abs(last-f[x][nw[x]].pos);
		last=f[x][nw[x]].pos;x^=1;
	} return ans+abs(last);
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read();
	for(LL i=1;i<=N;i++){
		f[0][i].l=read(),f[0][i].r=read(); f[0][i].id=i; 
		f[1][i]=f[0][i]; 
		f[0][i].pos=f[0][i].r; f[1][i].pos=f[0][i].l;
	} LL last=0;
	sort(f[1]+1,f[1]+N+1,cmpl);
	sort(f[0]+1,f[0]+N+1,cmpr);
	printf("%lld\n",max(solve(0),solve(1)));
	return 0;
}


