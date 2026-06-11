#include<bits/stdc++.h>
using namespace std;
const int maxn=1E5+5;
typedef long long int ll;
int n,size,head[maxn],ans[maxn];
ll a[maxn],sum[maxn];
map<ll,ll>what;
struct edge
{
	int to,next;
}E[maxn*2];
inline void add(int u,int v)
{
	E[++size].to=v;
	E[size].next=head[u];
	head[u]=size;
}
ll dfs(int u,int F,ll d)
{
	ll sum=0;
	for(int i=head[u];i;i=E[i].next)
	{
		int v=E[i].to;
		if(v==F)
			continue;
		ans[v]=u;
		sum+=dfs(v,u,d+1);
	}
	return sum+d;
}
inline void solve()
{
	for(int i=1;i<=n;++i)
		sum[i]=1;
	for(int i=1;i<n;++i)
	{
		ll x=a[i]-n+sum[what[a[i]]]*2;
		if(!what[x])
		{
			cout<<-1<<endl;
			exit(0);
		}
		add(what[x],what[a[i]]);
		sum[what[x]]+=sum[what[a[i]]];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		what[a[i]]=i;
	}
	ll g=a[1],pos=1;
	for(int i=2;i<=n;++i)
		if(a[i]<g)
			g=a[i],pos=i;
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	solve();
	if(dfs(pos,pos,0)!=g)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
		if(ans[i])
			cout<<i<<" "<<ans[i]<<endl;
	return 0;
}
