#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;

const int N=500005;

struct node{
	int x,y;
}p[N];
int h,w,n,lx,ly,ans;
map<int,int> mp[N];

bool cmp(node a,node b){
	return a.y<b.y||(a.y==b.y&&a.x<b.x);
}

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&h,&w,&n);
	for (i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y),mp[p[i].x][p[i].y]=1;
	sort(p+1,p+1+n,cmp); lx=2; ly=1; ans=h;
	for (i=1;i<=n;i++) if (p[i].y==1) ans=min(ans,p[i].x-1);
	for (i=1;i<=n;i=j+1){
		j=i;
		for (k=i;k<n&&p[k+1].y==p[i].y;k++);
		j=k;
		while (p[i].x<p[i].y&&i<=j) i++;
		if (i>j) continue;
		if (p[i].y==1) continue;
		if (lx+p[i].y-ly-1>=h) break;
		if (!mp[lx+p[i].y-ly-1][p[i].y]){
			lx+=p[i].y-ly-1;
			ly=p[i].y;
		}
		else{
			for (k=i;k<=j;k++) if (p[k].x+1<=h){
				if (p[k].x+2-lx>=p[k].y-ly&&!mp[p[k].x+1][p[k].y]){
					lx=p[k].x+1; ly=p[k].y;
					break;
				}
			}
		}
		if (ly<p[i].y) break;
		for (k=i;k<=j;k++) if (p[k].x>lx) ans=min(ans,p[k].x-1);
		if (lx>=h) break;
		if (mp[lx+1][ly]) break;
		lx++;
	}
	printf("%d\n",ans);
	return 0;
}