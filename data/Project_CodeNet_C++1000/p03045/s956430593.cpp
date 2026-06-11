#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int GCD(int x,int y){
  if(x<y){
    swap(x,y);
  }
  while(x%y!=0){
    int temp=x;
    x=y;
    y=temp%y;
  }
  return y;
}

int par[100001],r[100001];

void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    r[i]=0;
  }
}

int find(int x){
  if(par[x]==x){
    return x;
  }
  else{
    return par[x]=find(par[x]);
  }
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(r[x]<r[y]){
    par[x]=y;
  }
  else{
    par[y]=x;
    if(r[x]==r[y]) r[x]++;
  }
}

bool same(int x,int y){
  return find(x)==find(y);
}

int main() {
  int n,m;
  cin>>n>>m;
  init(n);
  for(int i=0;i<m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;
    unite(x,y);
  }
  set<int> memo;
  for(int i=0;i<n;i++){
    memo.insert(find(i));
  }
  cout<<memo.size()<<endl;
  return 0;
}
