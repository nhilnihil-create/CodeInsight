#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair < int , int > pii;
typedef pair < LL , int > pli;
#define mpr make_pair
#define FS first
#define SC second
#define PB push_back
template < typename T > T MAX(T a,T b){return (a>b)?a:b;}
template < typename T > T MIN(T a,T b){return (a<b)?a:b;}
template < typename T > void UMAX(T &a,T b){a=(a>b?a:b);}
template < typename T > void UMIN(T &a,T b){a=(a<b?a:b);}
int readint(){
	char c=getchar();
	int ret=0;
	while(!(c>='0' && c<='9')) c=getchar();
	while(c>='0' && c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
void putint(int v){
	if(!v){
		putchar('0');
		return;
	}
	if(v>=10) putint(v/10);
	putchar('0'+(v%10));
}
int n,fa[100005],sz[100005];
pli D[100005];
vector < int > adj[100005];
multiset < LL > inp,ex;
LL sm[100005];
LL dfs(int v,int f,int d=0){
	int i;
	LL ret=(LL)d;
	for(i=0;i<(int)adj[v].size();++i){
		int u=adj[v][i];
		if(u!=f) ret+=dfs(u,v,d+1);
	}
	return ret;
}
void rdfs(int v,int f){
	int i;
	ex.insert(sm[v]);
	for(i=0;i<(int)adj[v].size();++i){
		int u=adj[v][i];
		if(u!=f){
			sm[u]=sm[v]+(LL)n-2ll*sz[u];
			rdfs(u,v);
		}
	}
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		fa[i]=-1;
		sz[i]=1;
		scanf("%lld",&D[i].FS);
		inp.insert(D[i].FS);
		D[i].SC=i;
	}
	sort(D,D+n);
	for(i=n-1;i>0;--i){
		int v=D[i].SC;
		LL d=D[i].FS,tar=d-(LL)n+2ll*sz[v];
		if(sz[v]*2>=n){
			printf("-1\n");
			return 0;
		}
		int td=lower_bound(D,D+n,mpr(tar,-1))-D;
		if(td>=n || D[td].FS!=tar || fa[D[td].SC]!=-1){
			printf("-1\n");
			return 0;
		}
		fa[v]=D[td].SC;
		sz[D[td].SC]+=sz[v];
	}
	if(sz[D[0].SC]!=n){
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n;++i){
		if(fa[i]!=-1){
			adj[i].push_back(fa[i]);
			adj[fa[i]].push_back(i);
		}
	}
	sm[D[0].SC]=dfs(D[0].SC,-1);
	rdfs(D[0].SC,-1);
	if(ex!=inp){
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n;++i){
		if(fa[i]!=-1) printf("%d %d\n",i+1,fa[i]+1);
	}
	return 0;
}
/*
 * 代码框架
 * 1、读入，对pair排序
 * 2、维护每个点的子树大小（初始=1）和父亲（初始=-1）
 * 3、按照D降序枚举，对于除了最后一个结点以外，都二分出其父亲的位置，找不到就-1
 * 4、每次如果碰到已经确定父亲的点则-1，如果碰到未确定父亲的点就加size
 * 5、最后检查，是否根节点的size=n
*/