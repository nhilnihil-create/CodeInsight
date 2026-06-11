#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;


// 素集合データ構造
struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }

  // データxが属する木の根を得る 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

  // 2つのデータx, yが属する木をマージする 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

  // 2つのデータx, yが属する木が同じならtrueを返す
    bool same(int x, int y) {
      return root(x) == root(y);
    }

  // データxが含まれる木の大きさを返す
    ll size(int x) {
        return -r[root(x)];
    }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  UnionFind UF(n);

  rep(i,m) {
    ll x, y;
    cin >> x >> y;
    UF.unite(x-1,y-1);
  }

  ll ans = 0;
  rep(i,n) {
    if (UF.same(a[i]-1, i)) ++ans;
  }
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}