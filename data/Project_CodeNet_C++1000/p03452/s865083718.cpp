#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=200005;
int n,m,fa[N];
LL dist[N];
int getfa(int x)
{
	if(fa[x]==x) return x;
	int ff=fa[x]; LL len=dist[x];
	fa[x]=getfa(fa[x]);
	dist[x]=dist[ff]+len;
	return fa[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	//puts("");
	for(int i=1;i<=m;i++)
	{
		int l,r; LL d; scanf("%d%d%lld",&l,&r,&d);
		int x=getfa(l),y=getfa(r);
		//cout<<i<<"  "<<x<<' '<<y<<' '<<fa[x]<<' '<<fa[y]<<endl;
		//for(int j=1;j<=n;j++) cout<<dist[j]<<' '; cout<<endl;
		if(x!=y){
			LL d1=dist[l],d2=dist[r];
			//cout<<d1<<" "<<d2<<endl;
			if(d1+d>=d2){
				fa[y]=x; dist[y]=dist[x]+d1+d-d2;
			}
			else{
				fa[x]=y; dist[x]=dist[y]+d2-d1-d;
			}
			//fa[y]=x; dist[y]=dist[x]+d;
		}
		else{
			if(dist[r]-dist[l]!=d) {printf("No\n");return 0;}
		}
		//cout<<"Di"<<' ';for(int i=1;i<=n;i++) cout<<dist[i]<<' '; cout<<endl;
		//cout<<"Fa"<<' ';for(int i=1;i<=n;i++) cout<<fa[i]<<' '; cout<<endl<<endl;
	}
	for(int i=1;i<=n;i++)
	  if(dist[i]>1e9) {printf("No\n");return 0;}
	printf("Yes\n");
	return 0;
}
