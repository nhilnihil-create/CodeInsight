#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int v[n];
  rep(i,0,n) cin>>v[i];
  map<int,int> a;
  map<int,int> b;
  rep(i,0,n){
    if(i%2==0){
      a[v[i]]++;
    }
    else{
      b[v[i]]++;
    }
  }
  P af=P(-1,0);
  P as=P(-1,0);
  for(auto p:a){
    if(p.second>af.second){
      as=af;
      af=p;
    }
    else if(p.second>as.second){
      as=p;
    }
  }
  P bf=P(-1,0);
  P bs=P(-1,0);
  for(auto p:b){
    if(p.second>bf.second){
      bs=bf;
      bf=p;
    }
    else if(p.second>bs.second){
      bs=p;
    }
  }
  if(af.first!=bf.first){
    cout<<n-(af.second+bf.second)<<endl;
  }
  else{
    cout<<n-max((af.second+bs.second),(as.second+bf.second))<<endl;
  }
}