#include <bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll n,ds,d[N],sz[N];map<ll,int>S;pair<int,int>v[N];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&d[i]),S[d[i]]=i,sz[i]=1;
	sort(d+1,d+n+1);
	for(int i=n;i>1;i--)
    {
		int p=S[d[i]];ll d2=d[i]-(n-sz[p])+sz[p];
		if(S.find(d2)==S.end()){puts("-1");return 0;}
		int q=S[d2];sz[q]+=sz[p];ds+=sz[p];
		v[n-i+1]=make_pair(p,q);
	}
	if(d[1]!=ds){puts("-1");return 0;}
	for(int i=1;i<n;i++) printf("%d %d\n",v[i].first,v[i].second);
}