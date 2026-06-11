#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N,K,Q;
  cin>>N>>K>>Q;
  vector<ll> v(N);
  rep(i,N) cin>>v[i];
  ll ans = INF;
  rep(i,N){
    ll m = v[i];
    ll l = -1LL,r=1000000005LL;
    while(r-l>1){
      ll mid = (l+r)/2LL;
      vector<ll> c(N);
      vector<ll> ze;
      ze.push_back(-1LL);
      vector<ll> cnt(N+1);
      rep(j,N) {
        if(v[j]<m) {
          c[j] = 0;
          ze.push_back(j);
        }
        else if(v[j]<=m+mid) {
          c[j] = 1;
          cnt[j+1]++;
        }
        else c[j] = 2; 
      }
      ze.push_back(N);
      ll possible = 0;
      rep(j,N) cnt[j+1] += cnt[j];
      rep(j,(int)ze.size()-1){
        if(ze[j+1]-ze[j]-1<K) continue;
        possible += min(cnt[ze[j+1]]-cnt[ze[j]+1],ze[j+1]-ze[j]-K);
      }
      if(possible>=Q) r = mid;
      else l = mid;
    }
    if(r!=1000000005) chmin(ans,r);
  }
  cout<<ans<<endl;
}