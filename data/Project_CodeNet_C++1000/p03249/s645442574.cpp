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
const int MAXN = 200010;
const LL INF = 2147483600;

struct dat{
	LL id,val;
}a[MAXN+1]; LL N;
bool cmpval(dat a,dat b){
	return a.val>b.val;
}
LL Node[MAXN<<1],Next[MAXN<<1],Root[MAXN+1],cnt;
inline void insert(LL u,LL v){
	Node[++cnt]=v; Next[cnt]=Root[u]; Root[u]=cnt; return ;
} LL sz[MAXN+1],f[MAXN+1],b[MAXN+1];
inline void dfs(LL k,LL Fa){
	sz[k]=1; for(LL x=Root[k];x;x=Next[x]){
		LL v=Node[x]; if(v==Fa) continue;
		dfs(v,k); sz[k]+=sz[v]; f[1]+=sz[v];
	} return ;
}
inline void dfs2(LL k,LL Fa){
	if(f[k]!=b[k]){ puts("-1"); exit(0); }
	for(LL x=Root[k];x;x=Next[x]){
		LL v=Node[x]; if(v==Fa) continue;
		f[v]=f[k]+N-2*sz[v]; dfs2(v,k);
	} return ;
} LL s1[MAXN+1],s2[MAXN+1],top;

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read();
	for(LL i=1;i<=N;i++){
		a[i].id=i; a[i].val=read(); b[i]=a[i].val;
	} sort(a+1,a+N+1,cmpval);
	for(LL i=1;i<=N;i++) sz[i]=1;
	for(LL i=1;i<N;i++){
		LL val=a[i].val-N+2*sz[i]; 
		LL l=i+1,r=N,pos=-1;
		while(l<=r){
			LL mid=(l+r)>>1;
			if(a[mid].val>=val) pos=mid,l=mid+1;
			else r=mid-1;
		} if(pos==-1||a[pos].val!=val){
			puts("-1"); return 0;
		} sz[pos]+=sz[i];
		s1[++top]=a[i].id; s2[top]=a[pos].id;
		insert(a[i].id,a[pos].id);
		insert(a[pos].id,a[i].id);
		//sz=N+a[fa]-a[i].val
	} dfs(1,0); dfs2(1,0);
	for(LL i=1;i<=top;i++) printf("%lld %lld\n",s1[i],s2[i]); 
	return 0;
}


