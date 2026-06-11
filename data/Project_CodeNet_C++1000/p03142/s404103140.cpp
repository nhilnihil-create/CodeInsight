#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <deque>
#include <iterator>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n, m; cin >> n >> m;
  vvll edges(n, vll());
  vll indeg(n, 0);
  REP(i, n+m-1) {
    ll a, b; cin >> a >> b;
    edges[a-1].push_back(b-1);
    indeg[b-1]++;
  }

  queue<ll> q;
  vll parent(n, -1);
  REP(i, n) {
    if (indeg[i]==0) {
      q.push(i); parent[i]=0; break;
    }
  }

  while(!q.empty()) {
    ll i = q.front(); q.pop();
    REP(j, edges[i].size()) {
      indeg[edges[i][j]]--;
      if (indeg[edges[i][j]] == 0) {
        q.push(edges[i][j]); parent[edges[i][j]] = i+1;
      }
    }
  }

  REP(i, n) cout << parent[i] << endl;

  return 0;
}
