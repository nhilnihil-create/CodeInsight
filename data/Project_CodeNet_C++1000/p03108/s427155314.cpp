#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct UnionFind{
  vector<ll>par;
  vector<ll>size;
  UnionFind(ll n):par(n),size(n){
    for(ll i=0;i<n;i++){
      par[i]=i;
      size[i]=1;
    }
  }
  ll root(ll x){
    return par[x]==x?x:par[x]=root(par[x]);
  }
  bool same(ll x,ll y){
    return root(x)==root(y);
  }
  void unit(ll x,ll y){
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(size[x]<size[y]){
      par[x]=y;
      size[y]+=size[x];
    }else{
      par[y]=x;
      size[x]+=size[y];
    }
  }
  ll treesize(ll x){
    return size[root(x)];
  }
};
int main(){
  ll n,m;
  cin>>n>>m;
  vector<pair<ll,ll>>edge(m);
  for(ll i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    edge[i].first=a;
    edge[i].second=b;
  }
  reverse(edge.begin(),edge.end());

  ll all=n*(n-1)/2;
  //cout<<all<<endl;
  vector<ll>ans;
  ans.push_back(all);
  UnionFind uf(n);
  for(ll i=0;i<m;i++){
    ll x=edge[i].first;
    ll y=edge[i].second;
    if(!uf.same(x,y)){  
      ll size_x_tree=uf.treesize(x);
      ll size_y_tree=uf.treesize(y);
     // cout<<size_x_tree<<" "<<size_y_tree<<endl;
      all-=size_x_tree*size_y_tree;
      uf.unit(x,y);
    }
    ans.push_back(all);
    //cout<<all<<endl;
  }

  reverse(ans.begin(),ans.end());
  for(ll i=1;i<=m;i++){
    cout<<ans[i]<<endl;
  }
}