#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define MN 50005
using namespace std;
int n,m,k,val[MN],c[MN][2],id[MN],fa[MN],ht[MN],sz[MN],ans=0x3f3f3f3f;bool vis[MN];
bool cmp(int x,int y){return val[x]>val[y];}
multiset<int> s;
multiset<int>::iterator it;
int merge(int x,int y){
	if((!x)||(!y))return x+y;
	if(val[x]>val[y])swap(x,y);
	c[x][1]=merge(c[x][1],y);
	if(ht[c[x][0]]<ht[c[x][1]])swap(c[x][0],c[x][1]);
	ht[x]=ht[c[x][1]]+1;sz[x]=sz[c[x][0]]+sz[c[x][1]]+1;return x;
}
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main(){
	scanf("%d%d%d",&n,&m,&k);int x,y,tmp;
	for(int i=1;i<=n;i++)scanf("%d",&val[i]),id[i]=fa[i]=i,sz[i]=1,ht[i]=0;sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;i++){
		vis[id[i]]=1;
		if(vis[id[i]-1]){
			x=getfa(id[i]),y=getfa(id[i]-1);
			if(val[x]>val[y]&&sz[y])swap(x,y);if(sz[y])fa[y]=x;merge(x,y);
		}
		if(vis[id[i]+1]){
			x=getfa(id[i]),y=getfa(id[i]+1);
			if(val[x]>val[y]&&sz[y])swap(x,y);if(sz[y])fa[y]=x;merge(x,y);
		}tmp=getfa(id[i]);
		while(sz[tmp]>=m)s.insert(val[tmp]),x=merge(c[tmp][0],c[tmp][1]),fa[tmp]=x,fa[x]=x,tmp=x;
		while(s.size()>k)it=s.end(),--it,s.erase(it);
		if(s.size()==k)it=s.end(),--it,ans=min(ans,(*it)-val[id[i]]);
	}printf("%d\n",ans);
}