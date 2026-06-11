#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
  int n,k;
  cin >> n >> k;
  vector<P> v(n);
  rep(i,n) cin >> v[i].first >> v[i].second;
  sort(v.begin(),v.end());

  ll ans = 5L*1e18L;
  rep(l,n-k+1){
    vector<ll> y;
    rep(i,k-1) y.push_back(v[l+i].second);
    for(int r=l+k-1;r<n;++r){
      y.push_back(v[r].second);
      sort(y.begin(),y.end());
      ll dx = v[r].first - v[l].first;
      ll dy = 1e18L;
      rep(i,y.size()-k+1) dy = min(dy,y[i+k-1]-y[i]); 
      ans = min(ans,dx*dy);
    }
  }
  cout << ans << endl;
}