#include <bits/stdc++.h>
using namespace std;
int N,M;
bool Graph[50][50];
bool went[50];
void dfs(int a){
  went[a]=true;
  for(int i=0;i<M;i++){
    if(!Graph[i][a])continue;
    if(went[i])continue;
    dfs(i);
  }
}
int main(){
  cin>>N>>M;
  vector<pair<int,int>>A(M);
  for(int i=0;i<M;i++){
    cin>>A[i].first>>A[i].second;
    A[i].first--;A[i].second--;
    Graph[A[i].first][A[i].second]=true;
    Graph[A[i].second][A[i].first]=true;
  }
  int ans=0;
  for(int i=0;i<M;i++){
    Graph[A[i].first][A[i].second]=false;
    Graph[A[i].second][A[i].first]=false;
    dfs(0);
    bool a=false;
    for(int j=0;j<N;j++)if(!went[j])a=true;
    if(a)ans++;
    for(int i=0;i<N;i++)went[i]=false;
    Graph[A[i].first][A[i].second]=true;
    Graph[A[i].second][A[i].first]=true;
  }
  cout<<ans<<endl;
}