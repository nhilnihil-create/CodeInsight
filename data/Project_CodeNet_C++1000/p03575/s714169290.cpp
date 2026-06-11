#include<bits/stdc++.h>
#define WHITE 0
#define GREY 1
#define BLACK 2
using namespace std;
int depth[500500];
vector<int> G[500500];
int color[500500];
int Ans;
int low[500500];
void dfs(int x,int last)
{
	color[x]=GREY;
	if(last!=-1)
		depth[x]=depth[last]+1;
	low[x]=depth[x];
	for(int i=0;i<(G[x].size());i++)
		if(G[x][i]!=last)
			if(color[G[x][i]]==WHITE)
			{
				dfs(G[x][i],x);
				low[x]=min(low[x],low[G[x][i]]);
			}
			else	low[x]=min(low[x],depth[G[x][i]]);
	if(low[x]==depth[x])
		Ans++;
	color[x]=BLACK;
}
int main()
{
	int N,K;
	cin>>N>>K;
	while(K--) 
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0,-1);
	cout<<Ans-1<<endl;
	return 0;
}