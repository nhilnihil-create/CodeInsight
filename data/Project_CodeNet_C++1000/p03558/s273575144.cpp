#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int> 

int K;
int dist[100010];
bool inh[100010];

main()
{
	ios::sync_with_stdio(false);
	
	cin>>K;
	
	int ans=1000000010;
	
	memset(dist,-1,sizeof(dist));
	priority_queue<pii> H;
	dist[1]=1;
	H.push({-1,1});
	inh[1]=true;
	
	while(!H.empty())
	{
		int u=H.top().second; H.pop();
		if(!inh[u]) continue;
		inh[u]=false; // cout<<u<<endl;
		if(u%K==0) ans=min(ans,dist[u]);
		int v=u*10%K;
		if(dist[v]==-1 || dist[v]>dist[u])
		{
			dist[v]=dist[u];
			H.push({-dist[v],v});
			inh[v]=true;
		}
		v=(u+1)%K;
		if(dist[v]==-1 || dist[v]>dist[u]+1)
		{
			dist[v]=dist[u]+1;
			H.push({-dist[v],v});
			inh[v]=true;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}










