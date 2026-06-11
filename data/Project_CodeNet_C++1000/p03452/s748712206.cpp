#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int par[100010];
int ra[100010];
int weight[100010];

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;ra[i]=0;weight[i]=0;
  }
  return;
}

int root(int n){
  if(par[n]==n){
    return n;
  }
  int r=root(par[n]);
  weight[n]+=weight[par[n]];
  return par[n]=r;
}

void unite(int x,int y,int w){
  int rx=root(x),ry=root(y);
  if(rx==ry){
    return;
  }
  if(ra[rx]<ra[ry]){
    par[rx]=ry;
    weight[rx]=-w-weight[x]+weight[y];
  }  
  else{
    par[ry]=rx;
    weight[ry]=w+weight[x]-weight[y];
    if(ra[rx]==ra[ry]) ra[rx]++;
  }
  return;
}

bool same(int x,int y){
  return root(x)==root(y);
}

int diff(int x,int y){
  return weight[x]-weight[y];
}

int main() {
  int n,m;
  cin>>n>>m;
  init(n);
  for(int i=0;i<m;i++){
    int l,r,d;
    cin>>l>>r>>d;
    if(same(l-1,r-1)){
      if(d==diff(r-1,l-1)) continue;
      else {
        cout<<"No"<<endl;
        return 0;
      }
    }
    else unite(l-1,r-1,d);
  }
  cout<<"Yes"<<endl;
  return 0;
}
