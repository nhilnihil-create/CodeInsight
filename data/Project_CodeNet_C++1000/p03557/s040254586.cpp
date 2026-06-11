#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n; cin >> n;
  vector<ll> a(n),b(n),c(n);

  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];

  sort(a.begin(), a.end());
  sort(c.begin(), c.end());
  ll ans = 0;
  for(int i = 0; i < n; i++){
    int now = b[i];
    ll low = lower_bound(a.begin(), a.end(), now) - a.begin();
    ll hig = n - (upper_bound(c.begin(), c.end(), now) - c.begin());
    ans += low * hig;
  }
  cout << ans << endl;
  return 0;
}
