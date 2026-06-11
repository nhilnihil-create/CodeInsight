#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 struct UnionFind {
   // コンストラクタ
     vector<int> par;

     UnionFind(int n) : par(n, -1) { } //初期化

     // メンバ関数
     void init(int n) { par.assign(n, -1); } //途中で初期化したいときに使う。

     int root(int x) {
         if (par[x] < 0) return x;
         else return par[x] = root(par[x]);
     }

     bool issame(int x, int y) {
         return root(x) == root(y);
     }

     void merge(int x, int y) {
         x = root(x); y = root(y);
         if (x == y) return; //root同じ場合
         if (par[x] > par[y]) swap(x, y); // merge technique
         par[x] += par[y];
         par[y] = x;
         return;
     }

     int size(int x) {
         return -par[root(x)];
     }
 };

 int main() {
   int N, M; cin >> N >> M;
   vector<int> p(N);
   rep(i, 0, N) cin >> p.at(i);

   UnionFind uf(N);

   rep(i, 0, M) {
     int x, y; cin >> x >> y;
     uf.merge(x - 1, y - 1);
   }

   int ans = 0;
   rep(i, 0, N) if (uf.issame(p.at(i) - 1, i)) ans++;

   cout << ans << endl;
 }
