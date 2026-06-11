#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
const ll INF = 99999999;
int main(){
  ll h,w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  vector<vector<ll>> dist(h,vector<ll>(w,-1));
  queue<pair<ll,ll>>q;
  
  auto push = [&]( pair<ll,ll> v, ll d ){
    if( dist[v.first][v.second] != -1 ) return;
    dist[v.first][v.second] = d;
    q.push(v);
  };
  rep(i,h){
    rep(j,w){
      if( a[i][j] == '#' ) push(make_pair(i,j),0);
    }
  }
  while(!q.empty()){
    pair<ll,ll> v = q.front();q.pop();
    ll vf = v.first;
    ll vs = v.second;
    ll d = dist[vf][vs];
    if( vf-1 >= 0 ) push(make_pair(vf-1,vs),d+1);
    if( vf+1 <= h-1 ) push(make_pair(vf+1,vs),d+1);
    if( vs-1 >= 0 ) push(make_pair(vf,vs-1),d+1);
    if( vs+1 <= w-1 ) push(make_pair(vf,vs+1),d+1);
  }
  rep(i,h) sort(dist[i].begin(),dist[i].end());
  ll ans = 0;
  rep(i,h){
    ans = max(ans,dist[i][w-1]);
  }
  printf("%lld\n",ans);
  return 0;
}