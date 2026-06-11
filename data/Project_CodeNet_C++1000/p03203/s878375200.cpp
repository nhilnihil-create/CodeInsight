#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int x,y;
}a[1444444];
int W[1444444];
bool cmp(Node x,Node y)
{
	return x.y<y.y||x.y==y.y&&x.x<y.x;
}
int main()
{
	int i,cnt,h,w,n,now,ans=1000000000;
	scanf("%d%d%d",&h,&w,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	cnt=n;
	for(i=1;i<=w;i++)
		a[++cnt].x=h+1,a[cnt].y=i;
	n=cnt;
	sort(a+1,a+n+1,cmp);
	now=1;
	W[0]=0;
	for(i=1;i<=w;i++)
	{
		W[i]=W[i-1]+1;
//		printf("%d %d|\n",i,W[i]); 
		while(now<=cnt&&a[now].y<i||a[now].y==i&&a[now].x<W[i])
			now++;
		while(now<=cnt&&a[now].y==i&&a[now].x==W[i])
			W[i]++,now++;
//		printf("%d|%d %d\n",i,a[now].y,now);
		if(a[now].y==i)
			ans=min(ans,a[now].x);
	}
	printf("%d\n",ans-1);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	return 0;
}
