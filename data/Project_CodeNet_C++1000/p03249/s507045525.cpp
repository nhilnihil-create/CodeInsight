#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;++i)
typedef long long ll;
char cch;
inline ll rd(){
	ll x=0,fl=1;
	cch=getchar();
	while(cch>'9'||cch<'0'){
		if(cch=='-') fl=-1;
		cch=getchar();
	}
	while(cch>='0'&&cch<='9') x=(x<<3)+(x<<1)+cch-'0',cch=getchar();
	return x*fl;
}
const int N=1e5+3;
struct abc{
	int i;
	ll d;
}a[N];
int fr[N],head[N],to[N],nxt[N],cnt,sz[N];
ll re,c[N];
inline bool cmp(const abc &a,const abc &b){
	return a.d<b.d;
}
inline void adde(int u,int v){
	to[++cnt]=v,fr[cnt]=u,nxt[cnt]=head[u],head[u]=cnt;
}
inline void dfs(int u,int fa,int dep){
	re+=dep;
	for(int i=head[u];i;i=nxt[i]){
		dfs(to[i],u,dep+1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n) a[i].d=rd(),a[i].i=i,sz[i]=1;
	sort(a+1,a+1+n,cmp);
	rep(i,1,n) c[i]=a[i].d;
	int pos;
	ll tmp;
	for(int i=n;i>1;--i){
		tmp=a[i].d-(n-sz[a[i].i])+sz[a[i].i];
		pos=lower_bound(c+1,c+n+1,tmp)-c;
		if(c[pos]!=tmp){
			puts("-1");return 0;
		}
		else sz[a[pos].i]+=sz[a[i].i],adde(a[pos].i,a[i].i);
	}
	dfs(a[1].i,0,0);
	if(re!=a[1].d){
		puts("-1");return 0;
	}
	for(int i=1;i<n;++i){
		printf("%d %d\n",fr[i],to[i]);
	}
}