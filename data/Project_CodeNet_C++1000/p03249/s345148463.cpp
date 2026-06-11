#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e6+100;
int n,v2[maxn],fa[maxn];
LL v[maxn],sz[maxn],ds[maxn];
map<LL,int> tp;
bool cmp(int a,int b){return v[a]<v[b];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&v[i]),tp[v[i]]=i,v2[i]=i,sz[i]=1;
	sort(v2+1,v2+n+1,cmp);
	for(int i=n;i>1;i--){
		long long tp2=v[v2[i]]-n+sz[v2[i]]*2;
		if(!tp[tp2]){
			puts("-1");
			return 0;
		}
		int sb=tp[tp2];
		ds[sb]+=ds[v2[i]]+sz[v2[i]];
		sz[sb]+=sz[v2[i]];
		fa[v2[i]]=sb;
	}
	if(ds[v2[1]]!=v[v2[1]]) puts("-1");
	else for(int i=1;i<=n;i++) if(fa[i]) printf("%d %d\n",i,fa[i]);
	return 0;
}