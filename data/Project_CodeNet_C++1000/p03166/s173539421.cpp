#include<bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>&edges,vector<bool>&visited,vector<int>&longest_path,int i){
  if(!visited[i]){
    visited[i]=true;
    int ans=-1;
    for(auto j:edges[i]){
      ans=max(ans,dfs(edges,visited,longest_path,j));
    }
    return longest_path[i]=1+ans;
  }
  else return longest_path[i];
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>edges(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    edges[a].push_back(b);
  }
  vector<bool>visited(n,false);
  vector<int>longest_path(n,-1);
  for(int i=0;i<n;i++)
  dfs(edges,visited,longest_path,i);
  int ans=0;
  for(auto i:longest_path)ans=max(i,ans);
  cout<<ans<<endl;
}