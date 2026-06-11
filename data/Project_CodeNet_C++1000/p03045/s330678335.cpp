#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)

/* exchange */
#define chmin(a, b) (a) = min((ll)(a), (ll)(b))
#define chmax(a, b) (a) = max((ll)(a), (ll)(b))

/* output */
#define I(x) cin >> x;
#define D(x) cerr << (x) << " ";
#define BR cerr << "\n";
#define P(x) cout << (x) << endl;
#define FIX cout << fixed << setprecision(10);

/* const */
const int ARRAY = 100005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

struct UnionFind {

  vector<ll> parent;
  vector<ll> cnt;

  UnionFind(ll N) {
    parent.resize(N);
    cnt.resize(N);
    REP(i, N) {
      parent[i] = i;
      cnt[i] = 1;
    }
  }

  ll root(ll i) {
    if (parent[i] == i) return i;
    else return parent[i] = root(parent[i]);
  }

  void unite(ll x, ll y) {
    ll rx = root(x);
    ll ry = root(y);
    if (rx != ry) {
      parent[rx] = ry;
      cnt[ry] += cnt[rx];
    }
  }

  bool same(ll x, ll y) {
    return root(x) == root(y);
  }

  ll size(ll x) {
    return cnt[root(x)];
  }

  vector<ll> member(ll x) {
    vector<ll> v;
    ll r = root(x);
    REP(i, parent.size()) {
      if (r == root(i)) v.pb(i);
    }
    return move(v);
  }
};

ll N = 0;
ll M = 0;
ll ret = 0;

int main(void){
  
  I(N);
  I(M);
  UnionFind uf(N);
  REP(i, M) {
    ll x, y, z;
    I(x);
    I(y);
    I(z);
    uf.unite(x-1, y-1);
  }

  vl root(N, -1);
  FOR(i, 0, N) {
    if (root[uf.root(i)] == -1) {
      ret++;
      root[uf.root(i)] = 1;
    }
  }

  P(ret);

}
