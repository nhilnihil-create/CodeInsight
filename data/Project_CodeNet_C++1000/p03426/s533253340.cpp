#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll 
int cost(int i,int j, int x, int y)
{return abs(i-x)+abs(j-y);}
#define x first
#define y second
int ans[90001];
pair<int,int> pos[90001];
int32_t main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n,m,D;
	cin>>n>>m>>D;int u;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			{cin>>u;pos[u]={i,j};}
	}
	for(int i=D+1;i<=n*m;i++)
	{
		ans[i]=ans[i-D]+cost(pos[i].x, pos[i].y, pos[i-D].x, pos[i-D].y);
	}
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<ans[r]-ans[l]<<"\n";
	}



	

}