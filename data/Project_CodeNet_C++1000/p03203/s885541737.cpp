#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
priority_queue<int,vector<int>,greater<int> >P[maxn];
int main()
{
	int n,m,Q;scanf("%d%d%d",&n,&m,&Q);
	while(Q--)
	{
		int x,y;scanf("%d%d",&x,&y);
		P[y].push(x);
	}
	int x=1,y=1,ans=n;
	for(int i=1;i<=m;i++)
	{
		int bottom=n;
		if(!P[i].empty())
			bottom=P[i].top()-1;
		ans=min(ans,bottom);
		x++;
		while(!P[i+1].empty()&&P[i+1].top()<x)
			P[i+1].pop();
		while(x<=n&&!P[i+1].empty()&&P[i+1].top()==x)
			P[i+1].pop(),x++;
	}
	printf("%d\n",ans);
	return 0;
}