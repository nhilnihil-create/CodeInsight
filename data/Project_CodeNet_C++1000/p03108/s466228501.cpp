#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

struct Unionfind {
  vector<int> d;

  Unionfind(int n) : d(n,-1) {}

  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }

  bool unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if(rx==ry) return false;
    if(d[rx] < d[ry]) swap(rx,ry);
    d[rx] += d[ry];
    d[ry] = rx;
    return true;
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  int size(int x) {
    return -d[root(x)];
  }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vll a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  Unionfind tree(n);
  vll ret;
  ll ans = n*(n-1LL)/2LL;
  per(i,m) {
    if(tree.same(a[i],b[i])) {
      ret.push_back(ans);
      continue;
    }
    ret.push_back(ans);
    ll as = (ll)tree.size(a[i]);
    ll bs = (ll)tree.size(b[i]);
    ans -= as*bs;
    tree.unite(a[i],b[i]);
  }
  reverse(ret.begin(),ret.end());
  rep(i,ret.size()) cout << ret[i] << endl;
  return 0;
}