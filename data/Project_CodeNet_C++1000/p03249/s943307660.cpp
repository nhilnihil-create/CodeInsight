#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
map<int ,int > s;
int sd[N],fa[N],rt,cnt[N],ne[N],tot,size[N],f[N],fi[N],zz[N],a[N],n;
int cmp(int x,int y){
	return a[x]>a[y];
}
void dfs(int x,int z){
	sd[x]=z;
	for (int i=fi[x];i;i=ne[i])dfs(zz[i],z+1);
}
void dfs2(int x){
	if (x!=rt)cnt[x]=cnt[fa[x]]+n-2*size[x];
	for (int i=fi[x];i;i=ne[i])dfs2(zz[i]);
}
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
signed main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),s[a[i]]=i,f[i]=i;
	sort(f+1,f+n+1,cmp);
	for (int i=1;i<=n;i++){
		size[f[i]]++;
		if (i==n)continue;
		if (!s.count(a[f[i]]-(n-2*size[f[i]]))){
			puts("-1");
			return 0;
		}
		int k=a[f[i]]-(n-2*size[f[i]]);
		size[s[k]]+=size[f[i]];fa[f[i]]=s[k];
		jb(s[k],f[i]);
	}
	rt=0;
	for (int i=1;i<=n;i++)
		if (!fa[i])dfs(i,0),rt=i;
	for (int i=1;i<=n;i++)cnt[rt]+=sd[i];	
	dfs2(rt);
	for (int i=1;i<=n;i++)
		if (a[i]!=cnt[i]){
			puts("-1");
			return 0;
		}	
	for (int i=1;i<=n;i++)
		if (fa[i])printf("%lld %lld\n",i,fa[i]);	
}