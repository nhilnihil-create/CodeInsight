#include<bits/stdc++.h>
#define N 100005
#define pb push_back
using namespace std;
inline void in(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
int dep[N],low[N],n,m,ans;
vector<int> v[N];
inline void chmin(int &x,int y){x=x<y?x:y;}
void tarjan(int from,int f)
{
	dep[from]=dep[f]+1;
	low[from]=dep[from];
	for(int i=0;i<v[from].size();++i)
	{
		int to=v[from][i];
		if(to==f)continue;
		if(!dep[to])
		{
			tarjan(to,from);
			chmin(low[from],low[to]);
		}
		else chmin(low[from],dep[to]);
	}
	if(from!=1&&low[from]==dep[from])++ans;
}
int main()
{
	in(n);in(m);
	while(m--)
	{
		int x,y;
		in(x);in(y);
		v[x].pb(y);
		v[y].pb(x);
	}
	tarjan(1,0);
	printf("%d\n",ans);
	return 0;
}