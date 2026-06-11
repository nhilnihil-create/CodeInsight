//Using DFS
#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int maxi = INT_MIN;
void dfs_helper(int src, int v,int e,list<int> *l,map<int,bool>&vis)
{
  vis[src]=true;
  list<int>::iterator it;

  for(it=l[src].begin();it!=l[src].end();++it)
  {
    if(!vis[*it])
      dfs_helper(*it,v,e,l,vis);
      
      dp[src] = max(dp[src],dp[*it]+1);
  }
  maxi = max(dp[src],maxi);
}
      
void dfs(int v,int e, list<int>* l)
{
  map<int,bool>vis;
  for(int i=1;i<=v;i++)
  {
    if(!vis[i])
      dfs_helper(i,v,e,l,vis);
  }
  cout<<maxi<<endl;
}
int main()
{
  int v,e;
  cin>>v>>e;
  list<int>l[v+1];
  while(e--)
  {
    int x,y;
    cin>>x>>y;
    l[x].push_back(y);
  }
  dfs(v,e,l);
}
