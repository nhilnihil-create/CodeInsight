#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<vector<int>>> &g,vector<int> &p,bool &f,vector<bool> &c,int x){
  if(!f)
    return;
  c.at(x)=1;
  for(auto v:g.at(x)){
    int y=v.at(0);
    int d=v.at(1);
    if(c.at(y)){
      if(p.at(y)!=p.at(x)+d)
        f=0;
      continue;
    }
    p.at(y)=p.at(x)+d;
    dfs(g,p,f,c,y);
  }
  return;
}
int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<vector<int>>> g(n);
  for(int i=0;i<m;i++){
    int l,r,d;
    cin>>l>>r>>d;
    l--;
    r--;
    g.at(l).push_back({r,d});
    g.at(r).push_back({l,-d});
  }
  vector<int> p(n,0);
  bool f=1;
  vector<bool> c(n,0);
  for(int i=0;i<n;i++){
    if(c.at(i))
      continue;
    dfs(g,p,f,c,i);
  }
  cout<<(f?"Yes":"No")<<endl;
}