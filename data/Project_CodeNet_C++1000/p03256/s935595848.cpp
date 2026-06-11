#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int N,M;
string s;
vector<int>G[2<<17];
int cnt[2][2<<17];
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
	queue<int>P;
	for(int i=0;i<N;i++)
	{
		for(int v:G[i])
		{
			cnt[s[v]=='A'?0:1][i]++;
		}
		if(!cnt[0][i]||!cnt[1][i])
		{
			P.push(i);
			cnt[0][i]=cnt[1][i]=0;
		}
	}
	while(!P.empty())
	{
		int u=P.front();
		P.pop();
		int id=s[u]=='A'?0:1;
		for(int v:G[u])
		{
			if(--cnt[id][v]==0)
			{
				cnt[1-id][v]=0;
				P.push(v);
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		if(cnt[0][i]>0&&cnt[1][i]>0)
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}