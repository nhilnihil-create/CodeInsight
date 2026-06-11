#include<bits/stdc++.h>
#define int long long
using namespace std;
int par[100100],idx[100100];
vector<int> G[100100],tps,g[100100];
bool ok[100100];
void dfs(int x){
  ok[x]=false;
  for(int i:G[x])
    if(ok[i])dfs(i);
  tps.push_back(x);
}
signed main(){
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N-1+M;i++){
    int a,b;
    cin>>a>>b;
    G[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }
  for(int i=0;i<N;i++)ok[i]=true;
  for(int i=0;i<N;i++)
    if(ok[i])dfs(i);
  reverse(tps.begin(),tps.end());
  idx[N]=-1;
  for(int i=0;i<N;i++){
    par[tps[i]]=N;
    for(int j:g[tps[i]])
      if(idx[par[tps[i]]]<idx[j])par[tps[i]]=j;
    idx[tps[i]]=i;
    if(i==0)par[tps[i]]=-1;
  }
  for(int i=0;i<N;i++)cout<<par[i]+1<<endl;
}