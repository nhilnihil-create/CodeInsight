#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;
const ll dv = 1000000007;

vector<ll> dy = {1,0,-1,0};
vector<ll> dx = {0,1,0,-1};


int main(){
  ll h,w;cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a.at(i);
  //そのマスが黒くなるまでの操作数
  vector<vector<ll>> dist(h,vector<ll>(w,-1));

  queue<P> q;
  auto push = [&]( ll y, ll x, ll d ){
    //すでに探索済みなら操作しない
    if( dist.at(y).at(x) != -1 ) return;
    //操作数を更新
    dist.at(y).at(x) = d;
    q.push(make_pair(y,x));
  };
  //1回目の操作
  for(ll i=0;i<h;++i){
    for(ll j=0;j<w;++j){
      if( a.at(i).at(j) == '#' ){
        push(i,j,0);
      }
    }
  }

  while( !q.empty() ){
    P p = q.front();q.pop();
    ll d = dist.at(p.first).at(p.second);
    for(ll i=0;i<4;++i){
      ll ny = p.first + dy.at(i);
      ll nx = p.second + dx.at(i);
      if( ny >= 0 && ny < h && nx >= 0 && nx < w ){
        push(ny,nx,d+1);
      }
    }
  }

  ll ans = -10;
  rep(i,h){
    rep(j,w){
      ans = max(ans,dist.at(i).at(j));
    }
  }
  cout << ans << endl;

  return 0;
}