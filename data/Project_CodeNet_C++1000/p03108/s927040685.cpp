#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int par[100000];
int ran[100000];
int num[100000];

void init(int n){
  rep(i,0,n){
    par[i]=i;
    ran[i]=0;
    num[i]=1;
  }
}

int find(int x){
  if(par[x]==x) return x;
  return par[x]=find(par[x]);
}

void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(ran[x]<ran[y]){
    par[x]=y;
    num[y]+=num[x];
  }
  else{
    par[y]=x;
    num[x]+=num[y];
    if(ran[x]==ran[y]) ran[x]++;
  }
}

int size(int x){
  return num[find(x)];
}

bool same(int x,int y){
  return find(x)==find(y);
}

int main(){
  ll n,m;
  cin>>n>>m;
  init(n);
  int a[m];
  int b[m];
  rep(i,0,m){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
  }
  ll ans[m+1];
  ans[0]=0;
  rep(i,0,m){
    if(same(a[m-1-i],b[m-1-i])){
      ans[i+1]=ans[i];
    }
    else{
      ans[i+1]=ans[i]+size(a[m-1-i])*size(b[m-1-i]);
      unite(a[m-1-i],b[m-1-i]);
    }
  }
  rep(i,0,m){
    cout<<n*(n-1)/2-ans[m-1-i]<<endl;
  }
}