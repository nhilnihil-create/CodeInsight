#include<iostream>
#include<vector>
using namespace std;
int N,M;
string s;
vector<int>G[2<<17];
vector<int>H[4<<17];
int color[4<<17];
bool dfs(int u,int p)
{
	color[u]=1;
	for(int v:H[u])
	{
		if(p==v)continue;
		else if(color[v]==1)return true;
		else if(color[v]==0&&dfs(v,u))return true;
	}
	color[u]=2;
	return false;
}
main()
{
	cin>>N>>M>>s;
	for(int i=0;i<M;i++)
	{
		int a,b;cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<N;i++)
	{
		for(int v:G[i])
		{
			if(s[i]=='A')
			{
				if(s[v]=='B')H[i*2].push_back(v*2);
				else H[i*2+1].push_back(v*2);
			}
			else
			{
				if(s[v]=='B')H[i*2].push_back(v*2+1);
				else H[i*2+1].push_back(v*2+1);
			}
		}
	}
	for(int i=0;i<N*2;i++)
	{
		if(color[i]==0)
		{
			if(dfs(i,-1))
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
}