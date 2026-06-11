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

bool v[1005][1005][1005];
int main() {
  int x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x),b(y),c(z);
  rep(i,x) cin >> a[i];
  rep(i,y) cin >> b[i];
  rep(i,z) cin >> c[i];
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  sort(c.rbegin(),c.rend());

  priority_queue<tuple<ll,int,int,int>> q;
  auto push = [&](int n,int m,int l){
    if(v[n][m][l]) return;
    v[n][m][l] = true;
    q.emplace(a[n]+b[m]+c[l],n,m,l);
  };
  push(0,0,0);
  rep(i,k){
    ll ans; int ai,bi,ci;
    tie(ans,ai,bi,ci) = q.top(); q.pop();
    cout << ans << endl;
    if(ai<x-1) push(ai+1,bi,ci);
    if(bi<y-1) push(ai,bi+1,ci);
    if(ci<z-1) push(ai,bi,ci+1);
  }  
}