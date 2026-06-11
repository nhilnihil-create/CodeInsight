#include <bits/stdc++.h>
#define NN 55
using namespace std;
set<int> Edge[NN];
int Low[NN],Depth[NN];
bool Vis[NN];
void Dfs(int X)
{
	Vis[X]=1;
	for(auto To:Edge[X])
	{
		if(Vis[To])
		{
			continue;
		}
		Dfs(To);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,M;
	cin>>N>>M;
	int x[55],y[55]; 
	for(int i=1;i<=M;i++)
	{
		int X,Y;
		cin>>X>>Y;
		x[i]=X;
		y[i]=Y;
		Edge[X].insert(Y);
		Edge[Y].insert(X);
	}
	int Cnt=0;
	for(int i=1;i<=M;i++)
	{
		Edge[x[i]].erase(y[i]);
		Edge[y[i]].erase(x[i]);
		memset(Vis,0,sizeof Vis);
		int Pos=-1;
		for(int j=1;j<=N;j++)
		{
			if(j!=x[i]&&j!=y[i])
			{
				Pos=j;
				break;
			}
		}
		if(Pos==-1)
		{
			continue;
		}
		Dfs(1);
		bool flag=true;
		for(int j=1;j<=N;j++)
		{
			if(!Vis[j])
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			Cnt++;
		}
		Edge[x[i]].insert(y[i]);
		Edge[y[i]].insert(x[i]);
	}
	cout<<M-Cnt<<endl;
	return 0;
}