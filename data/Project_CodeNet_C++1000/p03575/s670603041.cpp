#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;

struct UnionFind {
   vector<int> d;
   UnionFind(int n = 0) : d(n, -1) {}
   int find(int x) {
      if (d[x] < 0) return x;
      return d[x] = find(d[x]);
   }
   bool unite(int x, int y) {
      x = find(x);
      y = find(y);
      if (x == y) return false;
      if (d[x] > d[y]) swap(x, y);
      d[x] += d[y];
      d[y] = x;
      return true;
   }
   bool same(int x, int y) { return find(x) == find(y); }
   int size(int x) { return -d[find(x)]; }
};

int main() {
   int n, m;
   cin >> n >> m;
   vector<int> a(m), b(m);
   rep(i, 0, m) {
      cin >> a[i] >> b[i];
      a[i]--, b[i]--;
   }
   int ans = 0;
   rep(i, 0, m) {
      UnionFind uf(n);
      rep(j, 0, m) {
         if (j == i) continue;
         uf.unite(a[j], b[j]);
      }
      if (uf.size(0) < n) ans++;
   }
   cout << ans << endl;

   return 0;
}