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

int main() {
  int n,k;
  cin >> n >> k;

  vector<P> v(n);
  rep(i,n) {
    cin >> v[i].second >> v[i].first;
    v[i].second--;
  }
  sort(v.rbegin(),v.rend());

  ll tot = 0;
  ll x = 0; vector<int> c(n);
  rep(i,k){
    tot += v[i].first;
    if(c[v[i].second]==0) ++x;
    c[v[i].second]++;
  }

  ll ans = tot+x*x;
  int l = k-1,r = k;
  while(0<=l && r<n){
    P vl = v[l], vr = v[r];
    if(c[vl.second]<=1){ --l; continue; }
    if(c[vr.second]>0){ ++r; continue; }
    c[vl.second]--; c[vr.second]++; ++x;
    tot += vr.first - vl.first;
    ans = max(ans,tot+x*x);
    --l; ++r;
  }
  cout << ans << endl;
}