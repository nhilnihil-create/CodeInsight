#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;

int main() {
  int n,m;
  cin >> n >> m;
  priority_queue<ll, vector<ll>, greater<ll>> a;
  rep(i,0,n) {
    int ai;
    cin >> ai;
    a.push(ai);
  }
  priority_queue<P> card;
  rep(i,0,m) {
    int b; ll c;
    cin >> b >> c;
    card.push(P(c,b));
  }
  bool flag = false;
  rep(i,0,m) {
    P p = card.top(); card.pop();
    rep(j,0,p.second) {
      ll f = a.top();
      if (f < p.first) {
        a.pop();
        a.push(p.first);
      } else {
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  ll ans = 0;
  rep(i,0,n) {
    ans += a.top(); a.pop();
  }
  cout << ans << endl;
  return 0;
}
