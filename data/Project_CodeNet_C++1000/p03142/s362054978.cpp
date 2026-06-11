#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, m; cin >> n >> m;
  vvll nodes(n, vll());
  vll h(n, 0);
  REP(i, n+m-1) {
    ll a, b; cin >> a >> b;
    nodes.at(a-1).push_back(b-1);
    h.at(b-1)++;
  }

  queue<ll> q;
  vll par(n, -1);
  REP(i, n) if (h.at(i)==0) {
    q.push(i);  // 根は1個だけだけど
    par.at(i) = 0;
  }

  while(!q.empty()) {
    ll i = q.front(); q.pop();
    REP(j, nodes.at(i).size()) {
      ll to = nodes.at(i).at(j);
      h.at(to)--;
      if (h.at(to) == 0) {
        q.push(to);
        par.at(to) = i + 1;
      }
    }
  }

  REP(i, n) {
    cout << par.at(i) << endl;
  }
  return 0;
}
