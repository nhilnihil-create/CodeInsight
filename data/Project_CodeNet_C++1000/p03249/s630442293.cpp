#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1e5+5;
int n,fa[MN],siz[MN],id[MN];
ll d[MN];
inline bool cmp(int x,int y){return d[x]<d[y];}
map<ll,int>mp;
ll ans;
int h[MN],cnt,to[MN],nxt[MN];
inline void ins(int s,int t){
	to[++cnt]=t;nxt[cnt]=h[s];h[s]=cnt;
}
void dfs(int st,int fa=0,int dep=0){
	ans+=dep;for(reg int i=h[st];i;i=nxt[i])dfs(to[i],st,dep+1);
}
int main(){
	ios::sync_with_stdio(false);cin>>n;
	for(reg int i=1;i<=n;i++)cin>>d[i],id[i]=i,siz[i]=1,mp[d[i]]=i;
	sort(id+1,id+1+n,cmp);reg int cnt=0;
	for(reg int i=n;i>1;i--){
		reg int pos=id[i];reg ll fad=d[pos]+2ll*siz[pos]-n;
		if(!mp[fad]||fad>=d[pos])return 0*puts("-1");
		reg int fap=mp[fad];siz[fap]+=siz[pos];ins(fap,pos);
	}
	dfs(id[1]);if(d[id[1]]^ans)return 0*puts("-1");
	for(reg int i=1;i<=n;i++)for(reg int j=h[i];j;j=nxt[j])printf("%d %d\n",i,to[j]);
	return 0;
}