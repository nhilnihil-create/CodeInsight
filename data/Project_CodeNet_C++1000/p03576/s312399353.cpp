#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=4091001001001001001;
  //           3999999996000000001


int main() {
  ll n,k;
  cin>>n>>k;
  vector<P>v(n);//圧縮前座標
  vector<P>V(n);//圧縮前座標
  vector<ll>Vrev(n);//圧縮前座標


  vector<P>x(n);//x座標、id
  vector<P>y(n);//y座標、id


  rep(i,n){
    ll x1,y1;
    cin>>x1;
    cin>>y1;
    x[i]=make_pair(x1,i);
    y[i]=make_pair(y1,i);
    v[i]=make_pair(x1,y1);

  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  rep(i,n){
    ll idx=x[i].second;
    ll idy=y[i].second;
    V[idx].first=i;
    V[idy].second=i;//V[i番目頂点]=(圧縮ごx座標、圧縮ごy座標)
  }
  vector<vector<ll>> Vnew(n+1, vector<ll>(n+1,0));//1index
rep(i,n){
  ll xnow=V[i].first;
  ll ynow=V[i].second;
  Vnew[xnow][ynow]++;
}


  vector<vector<ll>> g(n+1, vector<ll>(n+1,0));//1index
  vector<vector<ll>> G(n+1, vector<ll>(n+1,0));//1index

  rep(i,n)rep(j,n){
    g[i+1][j+1]=g[i][j+1]+Vnew[i][j];
  }
  rep(j,n)rep(i,n){
    G[i+1][j+1]=G[i+1][j]+g[i+1][j+1];
  }
  /*
  rep(i,n+1)rep(j,n+1){
      cout<<G[i][j]<<'i'<<i<<'j'<<j<<endl;
}
*/
ll ans=INF;
rep(xl,n)rep(yl,n){
  for(ll xr=xl;xr<n;xr++){
    for(ll yr=yl;yr<n;yr++){
      ll area=G[xr+1][yr+1]-G[xl][yr+1]-G[xr+1][yl]+G[xl][yl];
    //  cout<<area<<"area "<<xr<<"xr "<<xl<<"xl "<<yr<<"yr "<<yl<<"yl"<<endl;
      if(area>=k){
        ll areas=(x[xr].first-x[xl].first)*(y[yr].first-y[yl].first);
      //  cout<<x[xr].first<<"xr "<<x[xl].first<<"xl "<<y[yr].first<<"yr "<<y[yl].first<<"yl"<<endl;

        ans=min(ans,areas);
      }
    }
  }
}
cout<<ans;



}
