#include<bits/stdc++.h>
using namespace std;

vector<int> v[100010];
int n,id[100010],l,r,mid,ans,siz[100010];
long long dis[100010],t;

bool cmp(int x,int y) {return dis[x]>dis[y];}

long long dfs(int x)
{
	long long ans=0;
	for (int i=0,sz=v[x].size(); i<sz; i++) ans+=dfs(v[x][i])+siz[v[x][i]];
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%lld",&dis[i]),id[i]=i;
	sort(id+1,id+1+n,cmp);
	for (int i=1; i<=n; i++) siz[i]=1;
	for (int I=1,i; I<n; I++)
	{
		i=id[I],t=dis[i]-n+2*siz[i],l=I+1,r=n,ans=-1;
		while (l<=r) {mid=(l+r)>>1; if (dis[id[mid]]<=t) r=mid-1,ans=mid; else l=mid+1;}
		if (ans==-1||dis[id[ans]]!=t) return puts("-1"),0;
		v[id[ans]].push_back(i),siz[id[ans]]+=siz[i];
	}
	if (dfs(id[n])!=dis[id[n]]) return puts("-1"),0;
	for (int i=1; i<=n; i++)
		for (int j=0,sz=v[i].size(); j<sz; j++) printf("%d %d\n",i,v[i][j]);
	return 0;
}