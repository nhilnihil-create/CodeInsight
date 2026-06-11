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

int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> G(n);
  vector<int> par(n,-1),dis(n,0);
  vector<int> cnt(n,0);
  for(int i=0;i<n-1+m;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    cnt[b]++;
  }
  queue<int> memo;
  for(int i=0;i<n;i++){
    if(cnt[i]==0){
      memo.push(i);
    }
  }
  while(!memo.empty()){
    int v=memo.front();
    memo.pop();
    for(auto nv:G[v]){
      dis[nv]=max(dis[v]+1,dis[nv]);
      if(dis[nv]==dis[v]+1) par[nv]=v;
      cnt[nv]--;
      if(cnt[nv]==0){
        memo.push(nv);
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<par[i]+1<<endl;
  }
  return 0;
}
