#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#define LL long long 
using namespace std;

const int M = 210001;
int n,m,k,a[M],s[M],W,ver[M],nex[M],head[M],cnt;
void add(int x,int y)
{
	ver[++cnt]=y, nex[cnt]=head[x], head[x]=cnt;
	ver[++cnt]=x, nex[cnt]=head[y], head[y]=cnt;
}
map<LL,int> mp;
struct vv
{
	LL x;
	int w;
} t[M];

bool cmp(vv a,vv b){return a.x>b.x;}
bool cmp1(vv a,vv b){return a.w<b.w;}

LL dfs(int x,int fa,int dp)
{
	LL S=s[x];
	for(int i=head[x];i;i=nex[i])
	{
		if(ver[i]==fa) continue;
		S+=dfs(ver[i],x,dp+1);
	}
	return S;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i].x);
		t[i].w=i; s[i]=1;
		mp[t[i].x]=i;
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<n;i++)
	{
		LL k=t[i].x+(LL)s[t[i].w]-n+s[t[i].w];
		if(k==t[i].x || mp.find(k)==mp.end())
		{
			printf("-1");
			return 0;
		}
		a[t[i].w]=mp[k];
		add(t[i].w,mp[k]);
		s[mp[k]]+=s[t[i].w];
	}
	LL k=dfs(t[n].w,0,0)-n;
	if(dfs(t[n].w,0,0)-n!=t[n].x) 
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<n;i++) printf("%d %d\n",t[i].w,a[t[i].w]);
}