#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int x,y,z,k;
  cin>>x>>y>>z>>k;
  ll a[x];
  ll b[y];
  ll c[z];
  rep(i,0,x) cin>>a[i];
  rep(i,0,y) cin>>b[i];
  rep(i,0,z) cin>>c[i];
  ll d[x*y];
  rep(i,0,x){
    rep(j,0,y){
      d[i*y+j]=a[i]+b[j];
    }
  }
  sort(d,d+(x*y));
  reverse(d,d+(x*y));
  
  ll e[min(k,x*y)*z];
  rep(i,0,min(k,x*y)){
    rep(j,0,z){
      e[i*z+j]=d[i]+c[j];
    }
  }
  sort(e,e+min(k,x*y)*z);
  reverse(e,e+min(k,x*y)*z);
  rep(i,0,k){
    cout<<e[i]<<endl;
  }
}