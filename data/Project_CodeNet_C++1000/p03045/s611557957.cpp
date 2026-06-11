#include<bits/stdc++.h>
#define int long long
using namespace std;
struct UnionFind{
    int par[10000000],size[10000000];
    UnionFind(int N){
        for(int i=0;i<N;i++){
            par[i]=i;
            size[i]=1;
        }
    }
    int find(int x){
        if(par[x]==x)return x;
        int y=find(par[x]);
        par[x]=y;
        return y;
    }
    void unite(int x,int y){
        x=find(x),y=find(y);
        if(size[x]>=size[y])swap(x,y);
        par[x]=y,size[y]+=size[x];
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
};
signed main(){
  int N,M;
  cin>>N>>M;
  UnionFind U(N);
  while(M--){
    int X,Y,Z;
    cin>>X>>Y>>Z;
    U.unite(X-1,Y-1);
  }
  int ans=0;
  for(int i=0;i<N;i++)
    if(U.par[i]==i)ans++;
  cout<<ans<<endl;
}