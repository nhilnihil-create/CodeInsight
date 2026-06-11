#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <bitset>

using namespace std;
using ll = long long;
using ld = long double;
const ll mod =  1000000007;
const ll inf = 1e18;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REP_FROM(i, j, n) for (ll i = (j); i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll power(ll base, ll exponent){ if(exponent % 2){ return power(base, exponent - 1) * base % mod; }else if(exponent){ ll root_ans = power(base, exponent / 2); return root_ans * root_ans % mod; }else{ return 1; }}
ll inverse(ll x){ return power(x, mod - 2);}
ll gcd(ll a, ll b) {if(a < b) gcd(b, a);ll r;while(r=a%b) {a=b;b=r;}return b;}
template<typename T> ll sum(T begin, T end) {return accumulate(begin, end, 0ll);}
struct combination{ vector<ll> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } ll C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };

struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0)
      return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return;
    if (par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
  }

  bool same(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
  int size(int x) { return -par[root(x)]; }
};


int bsearch(const vector<ll>& a, ll x){
  int lft = 0;
  int rgt = a.size();
  while (rgt - lft > 1) {
    int mid = (lft + rgt) / 2;
    if(a[mid] < x) {
      lft = mid;
    }
    else {
      rgt = mid;
    }
  }
  return lft;
}


signed main() {
  ios::sync_with_stdio(false);
  ll n, m;
  cin >> n >> m;
  vector<map<int, ll>> a(n);
  REP(i, n) a[i][i] = 0;
  UnionFind tree(n);
  REP(i, m) {
    ll l, r, d;
    cin >> l >> r >> d;
    l--;r--;
    if(tree.same(l, r)) {
      int root = tree.root(l);
      if(a[root][r] - a[root][l] != d) {
        cout << "No" << endl;
        return 0;
      }
      continue;
    }
    if(tree.size(l) < tree.size(r)) {
      swap(l, r);
      d = -d;
    }
    int root_l = tree.root(l);
    ll base = a[tree.root(l)][l] - a[tree.root(r)][r] + d;
    for(const auto value: a[tree.root(r)]) {
      a[tree.root(l)][value.first] = value.second + base;
    }
    tree.unite(l, r);
    if(root_l != tree.root(l)) {
      a[tree.root(l)] = a[root_l];
    }
  }
  cout << "Yes" << endl;
  return 0;
}
