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
  int n, m;
  cin >> n >> m;
  vi p(n);
  rep(i,n) {
    cin >> p[i];
    p[i]--;
  }
  Unionfind tree(n);
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    tree.unite(x,y);
  }
  int ans = 0;
  rep(i,n) if(tree.same(i,p[i])) ans++;
  cout << ans << endl;
  return 0;
}