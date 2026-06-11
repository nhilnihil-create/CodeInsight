#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[8] = {-1,0,1,-1,1,-1,0,1};
int sj[8] = {-1,-1,-1,0,0,1,1,1};

struct UnionFind {
  vector<int> d;
  // 子は親のIDを，根は木のサイズ*-1を持つ
  UnionFind(int n = 0): d(n,-1){}
  // rootを探索する
  int find(int x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  // 集合を統合する
  bool unite(int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  // 同じ集合に属しているか判定
  bool same(int x, int y) {return find(x) == find(y);}
  // xの属している集合のサイズを返す
  int size(int x) {return -d[find(x)];}
};

int main() {
  ll n, m;
  cin >> n >> m;
  UnionFind uf(n);
  vector<ll> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  ll ans = (n * (n-1)) / 2;
  vector<ll> v;
  rep(i, m){
    a[i]--;
    b[i]--;
    if (uf.same(a[i],b[i])){
      v.push_back(ans);
      continue;
    }
    ans -= uf.size(a[i]) * uf.size(b[i]);
    v.push_back(ans);
    uf.unite(a[i],b[i]);
  }

  v.pop_back();
  reverse(v.begin(), v.end());
  v.push_back((n * (n-1)) / 2);

  rep(i,v.size()) cout << v[i] << endl;

  return 0;
}
