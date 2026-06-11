#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

int main(){
  ll N,K;
  cin >> N >> K;
  vector<vector<ll>> G(N);
  for(int i=0; i<N; i++){
    ll t,d;
    cin >> t >> d;
    t--;
    G[t].push_back(d);
  }
  vector<ll> y0,y1;
  for(int i=0; i<N; i++){
    if(G[i].size() == 0) continue;
    sort(G[i].begin(),G[i].end(),greater<ll>());
    for(int j=0; j<G[i].size(); j++){
      if(j){
        y0.push_back(G[i][j]);
      }else{
        y1.push_back(G[i][j]);
      }
    }
  }
  sort(y0.begin(),y0.end(),greater<ll>());
  sort(y1.begin(),y1.end(),greater<ll>());
  ll ans = 0;
  ll var= max(0,(int)(K-y0.size()));
  ll res = 0;
  for(int i=0; i<var; i++){
    res += y1[i];
  }
  for(int i=0; i<K-var; i++){
    res += y0[i];
  }
  while(1){
    ans = max(ans,res + var*var);
    if(K<=var || y1.size()<=var){
      break;
    }
    res += y1[var];
    res -= y0[K-var-1];
    var++;
  }
  cout << ans << endl;
  return 0;
}
