#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=1e5+2;
int n;
map<LL,int> mp;
LL dis[maxn];
int id[maxn],fa[maxn],siz[maxn];
bool cmp(int x,int y){
	return dis[x]>dis[y];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&dis[i]);
		siz[i]=1;
		id[i]=mp[dis[i]]=i;
	}
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<n;i++){
		fa[id[i]]=mp[dis[id[i]]-n+2*siz[id[i]]];
		if (!fa[id[i]]){
			puts("-1");
			return 0;
		}
		siz[fa[id[i]]]+=siz[id[i]];
	}
	for (int i=1;i<n;i++) dis[id[n]]-=siz[id[i]];
	if (dis[id[n]]){
		puts("-1");
		return 0;
	}
	for (int i=1;i<n;i++) printf("%d %d\n",fa[id[i]],id[i]);
	return 0;
}