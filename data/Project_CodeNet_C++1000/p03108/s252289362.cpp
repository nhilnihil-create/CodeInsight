#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct union_find{
  //sizeバージョン
  vector<ll> par;
  vector<ll> size;
  union_find(ll n):par(n),size(n){
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
  union_find uf(N);
  vector<pair<ll,ll>> dot(M);
  for(ll i=0;i<M;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    dot[M-1-i].first=a;
    dot[M-1-i].second=b;
  }
  
  ll res=N*(N-1)/2;//すべての道順
  
  vector<ll> ans;
  for(ll i=0;i<M;i++){
    ans.push_back(res);
    ll a=dot[i].first;
    ll b=dot[i].second;
    if(uf.same(a,b))continue;
    ll sa=uf.treesize(a);
    ll sb=uf.treesize(b);
    res-=sa*sb;
    uf.unit(a,b);
  }
  reverse(ans.begin(),ans.end());
  for(ll i=0;i<M;i++)cout<<ans[i]<<endl;
}