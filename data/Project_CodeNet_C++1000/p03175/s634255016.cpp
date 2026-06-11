#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD=1e9+7;
vector<int> white,black;
vector< vector<int> > adj;
void dfs(int curr, int prev)
{
  for(auto u:adj[curr])
  { //int u=adj[curr][i];
    if(u!=prev)
	dfs(u,curr);	
  }
  white[curr]=1;black[curr]=1;
  for(auto u:adj[curr])
  {// int u=adj[curr][i];
  	if(u!=prev)
  	{
  	 	white[curr]=(white[curr]*((white[u]+black[u])%MOD))%MOD;
  	 	black[curr]=(black[curr]*white[u])%MOD;
	}
  }
}
//This is a program to compute the painters partition problem;
signed main()
{
 int n;cin>>n;
 adj.resize(n+1);white.resize(n+1);black.resize(n+1);
 for(int i=1;i<n;i++)
 {
 	int x,y;cin>>x>>y;
 	adj[x].push_back(y);
 	adj[y].push_back(x);
 }
 dfs(1,0);
 cout<<(white[1]+black[1])%MOD<<endl;
}
