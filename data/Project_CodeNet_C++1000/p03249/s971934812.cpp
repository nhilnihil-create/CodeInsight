#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
struct node
{
	long long d;int p;
}a[100010];
struct bian
{
	int x,y,next;
}e[100010];int len,last[100010];
void ins(int x,int y)
{
	len++;
	e[len].x=x;e[len].y=y;
	e[len].next=last[x];last[x]=len;
}
bool cmp(node a,node b){return a.d<b.d;}
int n;
bool v[100010];
inline int erfen(long long x)
{
	int l=1,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid].d<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if(a[ans].d==x)return ans;
	else return -1;
}
int tot[100010];
long long sum=0;
void dfs(int x,int dis)
{
	sum+=dis;
	for(int k=last[x];k;k=e[k].next)
	{
		int y=e[k].y;
		dfs(y,dis+1);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].d),a[i].p=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)tot[i]=1;
	bool bk=true;
	for(int i=n;i>1;i--)
	{
		long long ul=a[i].d-n+2*tot[i];
		int y=erfen(ul);
		if(y==-1 || y==i){bk=false;break;}
		ins(a[y].p,a[i].p);
		tot[y]+=tot[i];
	}
	dfs(a[1].p,0);
	if(bk==false || sum!=a[1].d)printf("-1\n");
	else for(int i=1;i<=len;i++)printf("%d %d\n",e[i].x,e[i].y);
    return 0;
}