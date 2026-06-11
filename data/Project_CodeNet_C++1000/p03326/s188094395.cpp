#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,w) for (int i = 0;i < (w); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;

int main(){
  int n,m;cin >> n >> m;
  vector<ll> x(n),y(n),z(n);
  rep(i,n) cin >> x[i] >> y[i] >> z[i];
  vector<ll> cons(n);
  ll ans = -1e18;
  rep(plus,1<<3){
    int a,b,c;
    if(plus>>0&1) a = 1;
    else a = -1;
    if(plus>>1&1) b = 1;
    else b = -1;
    if(plus>>2&1) c = 1;
    else c = -1;
    rep(i,n) cons[i] = a*x[i] + b*y[i] + c*z[i];
    sort(cons.rbegin(),cons.rend());
    ll sum = 0;
    rep(i,m) sum += cons[i];
    ans = max(ans,sum);
  }

  cout << ans << endl;
}