#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define drep(i,a,b) for(int i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
const int INF=INT_MAX;


int main(){
  ll h,w;cin>>h>>w;
  bool ok=true;
  vin dx={-1,0,1,0},dy={0,-1,0,1};
  vvb g(h,vb(w,0));
  rep(i,0,h){
    rep(j,0,w){
      char x;cin>>x;
      if(x=='#'){g[i][j]=1;}
    }
  }
  rep(i,0,h){
    rep(j,0,w){
      if(g[i][j]){
        bool ok2=false;
        rep(k,0,4){
          if(i+dx[k]<h&&i+dx[k]>=0&&j+dy[k]<w&&j+dy[k]>=0){
            if(g[i+dx[k]][j+dy[k]]){ok2=true;}
          }
        }
        if(!ok2){ok=false;}
      }
    }
  }
  if(ok){cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}