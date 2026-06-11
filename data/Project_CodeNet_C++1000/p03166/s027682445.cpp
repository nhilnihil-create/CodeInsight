#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
 
void topological(vector<int> graph[],vector<int> &vis,stack<int> &s,int u)
{
  vis[u]=1;
  for(int i=0;i<graph[u].size();i++)
  {
    if(vis[graph[u][i]]==0)
      topological(graph,vis,s,graph[u][i]);
  }
  s.push(u);
}
 
int main()
{
  ll n,m;
  cin>>n>>m;
  vector<int> graph[n];
  for(int i=0;i<m;i++)
  {
    ll x,y;
    cin>>x>>y;
    graph[x-1].push_back(y-1);
  }
  vector<int> vis(n,0);
  stack<int> s;
  for(int i=0;i<n;i++)
  {
    if(vis[i]==0)
      topological(graph,vis,s,i);
  }
 
  vector<ll> dis(n,0);
  while(!s.empty())
  {
    ll top=s.top();
    s.pop();
    for(int i=0;i<graph[top].size();i++)
    {
      if(dis[graph[top][i]]<dis[top]+1)
        dis[graph[top][i]]=dis[top]+1;
    }
  }
 
  ll maxi=0;
  for(int i=0;i<n;i++)
    maxi=max(maxi,dis[i]);
 
  cout<<maxi<<endl;
}