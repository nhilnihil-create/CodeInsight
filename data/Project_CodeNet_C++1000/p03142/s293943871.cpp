#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
using namespace std;
typedef long long ll;
using P=pair<int,int>;

class Edge
{
	public:
	int ind;
	int from;
	int to;

	Edge(int n,int c)
	{
		to=n;
		ind=c;
	}
};

vector<Edge> g[100000];
int ans[100000];
bool used[100000];
vector<int> tres;
void visit(int now)
{
	used[now]=true;
	for(int i=0;i<g[now].size();i++)
	{
		if(!used[g[now][i].to])
			visit(g[now][i].to);
	}
	tres.push_back(now);
	return;
}
void tsort(int n)
{
	tres.clear();
	fill(used,used+n,false);
	for(int i=0;i<n;i++)
	{
		if(!used[i])
			visit(i);
	}
	reverse(tres.begin(),tres.end());
}
int main()
{
	fill(ans,ans+100000,-1);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n-1+m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(Edge(b,i));
	}
	tsort(n);
	ans[tres[0]]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<g[tres[i]].size();j++)
		{
			Edge e=g[tres[i]][j];
			ans[e.to]=tres[i]+1;
		}
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<endl;
	return 0;
}