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
using P = pair<int,int>;

const ll INF = 1e18L;
int main() {
  int a,b,q;
  cin >> a >> b >> q;
  vector<ll> s(a),t(b);
  rep(i,a) cin >> s[i];
  rep(i,b) cin >> t[i];
  rep(qi,q){
    ll x;
    cin >> x;
    auto d = [&](ll p){ return abs(x-p); };
    int i = lower_bound(s.begin(),s.end(),x) - s.begin();
    int j = lower_bound(t.begin(),t.end(),x) - t.begin();
    ll ans = INF;
    ll ns = i<a?s[i]:INF;
    ll ps = i>0?s[i-1]:-INF;
    ll nt = j<b?t[j]:INF;
    ll pt = j>0?t[j-1]:-INF;
    ans = min(ans,d(max(ns,nt)));
    ans = min(ans,d(min(ps,pt)));
    ans = min(ans,min(d(ps),d(nt))*2 + max(d(ps),d(nt)));
    ans = min(ans,min(d(ns),d(pt))*2 + max(d(ns),d(pt)));
    cout << ans << endl;
  }
}