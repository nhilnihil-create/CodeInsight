#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#define ll long long
#define inf 20021225
#define mxn 200100
using namespace std;

int h,w,n,cnt;
struct node{int x,y;}p[mxn];
set<int> st[mxn];int ans;
void dfs(int x,int y,int stp)
{
	if(x>h||y>w)	return;
	set<int>::iterator it=st[y].lower_bound(x);
	if(it!=st[y].end())	ans=min(ans,stp+(*it)-x);
	it=st[y+1].find(x+1);
	if(it==st[y+1].end())
	{
		if(st[y].find(x+1)==st[y].end())	dfs(x+1,y+1,stp+1);
	}
	else	dfs(x+1,y,stp+1);
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);ans=h;
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y),st[p[i].y].insert(p[i].x);
	dfs(1,1,0);
	printf("%d\n",ans);
	return 0;
}