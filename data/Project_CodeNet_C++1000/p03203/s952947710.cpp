#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXS 200000

int h,w,n,ans;
int x[MAXS+3],y[MAXS+3];
int vis[MAXS+3];

int main() {
	scanf("%d %d %d",&h,&w,&n);
	ans=h;
	memset(vis,0x3f,sizeof(vis));
	for(int i=1;i<=n;i++) {
		scanf("%d %d",&x[i],&y[i]);
		if(x[i]>=y[i])
			vis[x[i]-y[i]]=min(vis[x[i]-y[i]],x[i]);
	}
	for(int i=1;i<=n;i++)
		if(x[i]>y[i])
			if(vis[x[i]-y[i]-1]>x[i])
				ans=min(ans,x[i]-1);
	printf("%d\n",ans);
	return 0;
}