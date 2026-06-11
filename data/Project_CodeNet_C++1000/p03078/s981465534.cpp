#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int x,y,z,k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x);
  vector<ll> b(y);
  vector<ll> c(z);
  rep(i,0,x) cin >> a[i];
  rep(i,0,y) cin >> b[i];
  rep(i,0,z) cin >> c[i];

  priority_queue<ll> abc;
  priority_queue<ll> ab;

  rep(i,0,x) rep(j,0,y){
    ll val=a[i]+b[j];
    ab.push(val);
  }

  sort(c.rbegin(), c.rend());
  ll e=min(x*y,k);

  rep(i,0,e){
    ll val1=ab.top(); ab.pop();
    rep(j,0,z){
      abc.push(val1+c[j]);
    }
  }

  rep(i,0,k){
    ll ans = abc.top(); abc.pop();
    cout << ans << endl;
  }
  return 0;
}