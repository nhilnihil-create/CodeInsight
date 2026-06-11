#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct Unionfind{
  vector<ll>par;
  vector<ll>size;
  Unionfind(ll n):par(n),size(n){
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
  ll N,M;
  cin>>N>>M;
  vector<pair<ll,ll>>edge(M);
  for(ll i=0;i<M;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    edge[i].first=a;
    edge[i].second=b;
  }
  reverse(edge.begin(),edge.end());
  Unionfind uf(N);
  ll res=N*(N-1)/2;
  vector<ll>ans;
  for(ll i=0;i<M;i++){
    ans.push_back(res);
    ll a=edge[i].first;
    ll b=edge[i].second;
    ////cout<<uf.root(a)<<uf.root(b)<<endl;
    //cout<<"a"<<a<<"b"<<b<<endl;
    if(!uf.same(a,b)){
      ll as=uf.treesize(a);
      ll bs=uf.treesize(b);
      //cout<<"treesize:"<<"as"<<a<<"bs"<<b<<endl;
      res-=as*bs;
      // //cout<<"a*b"<<a*b<<endl;
       uf.unit(a,b);
      //cout<<"res"<<res<<endl;
    }
    
    
  }
  reverse(ans.begin(),ans.end());
  for(ll i=0;i<M;i++){
    cout<<ans[i]<<endl;
  }
}
