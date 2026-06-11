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
  int n; ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll d = 1;
  vector<int> c;
  while(k>=d){
    int cnt = 0;
    rep(i,n) if((a[i]&d)>0) ++cnt;
    c.push_back(cnt);
    d <<= 1;
  }
  ll x = 0;
  int s = c.size();
  rep(i,s){
    int ii = s-1-i;
    if(c[ii]*2>=n) continue;
    ll d = 1LL<<ii;
    if(x+d>k) continue;
    x += d;
  }

  ll ans = 0;
  rep(i,n) ans += a[i]^x;
  cout << ans << endl;
}