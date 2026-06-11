#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

struct UnionFind{
  vector<int> par;
  UnionFind(int N):par(N){
    REP(i,N) par[i]=i;
  }
  int root(int x){
    if(par[x]==x) return x;
    return par[x]=root(par[x]);
  }
  void unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if(rx==ry) return;
    par[rx]=ry;
  }
  bool same(int x,int y){
    int rx=root(x);
    int ry=root(y);
    return rx==ry;
  }
};

int main(){
  int N,M; scanf("%d%d",&N,&M);
  vector<vector<int>> e1,e2;
  int a,b;
  REP(i,M){
    scanf("%d%d",&a,&b);
    e1.push_back({--a,--b});
  }
  bool t=true;
  while(t){
    t=false;
    UnionFind uf(N);
    REP(i,e2.size()){
      uf.unite(e2[i][0],e2[i][1]);
    }
    REP(i,e1.size()){
      if(uf.same(e1[i][0],e1[i][1])){
        e2.push_back(e1[i]);
        e1.erase(e1.begin()+i);
        t=true;
        break;
      }
      uf.unite(e1[i][0],e1[i][1]);
    }
  }
  printf("%d\n",e1.size());
}