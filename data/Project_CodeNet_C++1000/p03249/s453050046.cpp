#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
#define int long long
int n,sz[100100],u[100100],v[100100],head[100100],cnt,D;
struct Edge{
	int to,nxt;
}edge[200100];
struct node{
	int dis,x;
	bool operator<(node b)const{
		return dis>b.dis;
	}
}a[100100];
map<int,int>mp;
void addedge(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
int dfs(int x,int fa,int now){
	D+=now;
	for(int i=head[x];i;i=edge[i].nxt){
		int upup=edge[i].to;
		if(upup==fa)continue;
		dfs(upup,x,now+1);
	}
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].dis);
		a[i].x=i;
		mp[a[i].dis]=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sz[i]=1;
	for(int i=1;i<n;i++){
		int dis=a[i].dis,x=a[i].x;
		int tmp=dis-abs(n-2*sz[x]);
		int fa=mp.find(tmp)->second;
		if(fa==x||!fa)return puts("-1"),0;
		sz[fa]+=sz[x];
		D+=sz[a[i].x];
		u[i]=x,v[i]=fa;
		addedge(x,fa);
		addedge(fa,x);
	}
	//dfs(a[n].x,0,0);
	if(D!=a[n].dis)return puts("-1"),0;
	for(int i=1;i<n;i++)
		printf("%lld %lld\n",u[i],v[i]);
}