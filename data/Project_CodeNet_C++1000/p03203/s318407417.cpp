#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll h,w,n;
  cin >> h >> w >> n;
  vector<priority_queue<ll,vec,greater<ll>>> p(h+2);
  for(ll i=0;i<n;i++) {
    ll x,y;
    cin >> x >> y;
    p[x].push(y);
  }
  p[h+1].push(1);
  ll th=1;
  for(ll i=1;i<=h;i++) {
    if(p[i+1].size()) {
      if(p[i+1].top()<=th) {
        cout << i << endl;
        return 0;
      }
    }
    th++;
    if(p[i+1].size()) {
      if(p[i+1].top()==th) {
        th--;
      }
    }
  }
}