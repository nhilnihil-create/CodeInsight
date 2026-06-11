#include<bits/stdc++.h>
using namespace std;

int n=50;
int m=2500;
set<int>adj[50];
vector<pair<int,int>>edges;
bool marked[50];
int c=0;
void dfs(int s)
{
	marked[s]=true;
	c++;
	for(auto x:adj[s])
	{
	
		if(!marked[x]){
			//cout<<x<<" ";
			dfs(x);
		}
	}
	
}



int main()
{
	for(int i=0;i<50;i++)
		marked[i]=false;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;b--;
		adj[a].insert(b);
		adj[b].insert(a);
		edges.push_back({a,b});
	}
	int count=0;
	for(int i=0;i<m;i++)
	{
		int a = edges[i].first;
		int b = edges[i].second;
		adj[a].erase(b);
		adj[b].erase(a);
		dfs(0);
		if(c<n){
			count++;
			//cout<<c<<" ";
		}
		c=0;
		adj[a].insert(b);
		adj[b].insert(a);
		for(int i=0;i<50;i++)
			marked[i]=false;
	}

	cout<<count<<"\n";

}