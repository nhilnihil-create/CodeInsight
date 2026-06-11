#include <bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int n,m;
int par[MAXN];
int depth[MAXN];//parent , rank
int p[MAXN];
//n initialize
void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    depth[i]=0;
    cin>>p[i];
  }
  return;
}
// tree's root
int find(int x){
  if(par[x]==x){
    return x;
  }else{
    return par[x] = find(par[x]);
  }
}

void unite(int x,int y){
  x = find(x);
  y = find(y);
  if(x==y) return;
  if(depth[x]<depth[y]){
    par[x]=y;
  }else{
    par[y]=x;
    if(depth[x]==depth[y]) depth[x]++;
  }
  return;
}

bool same(int x,int y){
  return find(x)==find(y);
}

int main(){
  cin>>n>>m;
  init(n);
  for(int i=0;i<m;i++){
    int x,y; cin>>x>>y;
    unite(x,y);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(same(i+1,p[i])){
      ans++;
    }
  }
  cout<<ans<<endl;
}