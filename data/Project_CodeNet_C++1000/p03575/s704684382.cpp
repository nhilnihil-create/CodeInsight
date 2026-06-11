#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<vector<int>>> &g,vector<bool> &f,int i,int v){
  f.at(v)=1;
  for(auto e:g.at(v)){
    int ei=e.at(0);
    int ev=e.at(1);
    if(ei!=i&&!f.at(ev))
      dfs(g,f,i,ev);
  }
  return;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<vector<int>>> g(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    g.at(a).push_back({i,b});
    g.at(b).push_back({i,a});
  }
  int c=0;
  for(int i=0;i<m;i++){
    vector<bool> f(n,0);
    dfs(g,f,i,0);
    bool a=1;
    for(int j=0;j<n;j++)
      a&=f.at(j);
    c+=(a?0:1);
  }
  cout<<c<<endl;
}