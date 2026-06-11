#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,int>;

int main() {
  int n,m;
  cin >> n >> m;
  priority_queue<P, vector<P>, greater<P>> q;
  rep(i,0,n) {
    ll a; int b;
    cin >> a >> b;
    q.push(P(a,b));
  }
  ll ans = 0;
  while(m > 0) {
    P p = q.top(); q.pop();
    ans += p.first * min(m,p.second);
    m -= p.second;
  }
  cout << ans << endl;
  return 0;
}
