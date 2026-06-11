#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll H,W,D;
  cin>>H>>W>>D;
  vector<pair<ll,ll>> vp(H*W);
  for(ll i = 0; i < H; i++){
    for(ll j = 0; j < W; j++) {
      int x;
      cin>>x;
      vp[x-1]=make_pair(i,j);
    }
  }
  vector<vector<ll>> d(D);
  for(ll i = 0; i < D; i++){
    d[i].push_back(0);
    ll t = i;
    ll s = i+D;
    while(s<H*W){
      d[i].push_back(*(d[i].end()-1)+abs(vp[t].first-vp[s].first)+abs(vp[t].second-vp[s].second));
      t+=D;
      s+=D;
    }
  }
  ll Q;
  cin>>Q;
  for(ll i = 0; i < Q; i++){
    ll L,R;
    cin>>L>>R;
    L--;
    R--;
    cout<<d[R%D][R/D]-d[L%D][L/D]<<endl;
  }
}