#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m;
long long ans;
priority_queue<int,vector<int>,greater<int> >q;
struct node
{
	int x,y;
}a[maxn];
bool cmp(node tx,node ty)
{
	return tx.y>ty.y;
}
int main()
{
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&x),q.push(x);
	for(int i=1;i<=m;i++)scanf("%d %d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(a[i].y>q.top()&&(a[i].x--))
		{
			q.pop();
			q.push(a[i].y);
		}
	}
	while(!q.empty())ans+=q.top(),q.pop();
	printf("%lld\n",ans);
	return 0;
}