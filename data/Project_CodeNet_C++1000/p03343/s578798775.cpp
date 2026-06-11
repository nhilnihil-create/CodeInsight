#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
struct node{int w,id;}a[N];
bool cmp(node a,node b){
	return (a.w==b.w)?a.id<b.id:a.w<b.w;
}
int n,k,q,b[N],c[N],d[N],ans,vis[N];
int main(){
	ans=1e9+5;
	scanf("%d%d%d",&n,&k,&q);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i].w);
		b[i]=a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i){
		int l=1,r=0,cnt=0;
		while (r<=n){
			while (vis[l]) ++l;
			r=l;
			while (!vis[r]&&r<=n) ++r;
			int tot=0;
			for (int j=l;j<r;++j)
				c[++tot]=b[j];
			sort(c+1,c+tot+1);
			for (int j=1;j<=tot-k+1;++j)
				d[++cnt]=c[j];
			l=r;
		}
		if (cnt<q) break;
		sort(d+1,d+cnt+1);
		ans=min(ans,d[q]-a[i].w);	
		vis[a[i].id]=1;
	}
	printf("%d\n",ans);
}