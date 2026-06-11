#include<bits/stdc++.h>
#define max(a,b) (((a)>(b))?a:b)
#define min(a,b) (((a)<(b))?a:b)
#define int long long
using namespace std;
template<typename T>void read(T &x){
	x=0;int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	x*=f;
}
int n,fa[100010],sz[100010];
struct ha{int d,id;}a[100010];
bool cmp(ha x,ha y){
	return x.d>y.d;	
}
int dis;
vector<int>e[100010];
void dfs(int x,int d){
	dis+=d;
	int si=e[x].size();
	for(int i=0;i<si;++i)
		dfs(e[x][i],d+1);
}
signed main(){
	read(n);
	for(int i=1;i<=n;++i)
		read(a[i].d),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)
		sz[i]=1;
	for(int i=1;i<n;++i){
		int xx=a[i].d-(n-sz[a[i].id])+sz[a[i].id];
		int l=i+1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[mid].d==xx) {fa[a[i].id]=a[mid].id;sz[a[mid].id]+=sz[a[i].id];e[a[mid].id].push_back(a[i].id);break;}
			else if(a[mid].d<xx) r=mid-1;
			else l=mid+1;
		}
		if(!fa[a[i].id]) {puts("-1");return 0;}
	}
	dfs(a[n].id,0);
	if(dis!=a[n].d) {puts("-1");return 0;}
	for(int i=1;i<=n;++i)
		if(fa[i]) printf("%d %d\n",i,fa[i]);
	return 0;
}
