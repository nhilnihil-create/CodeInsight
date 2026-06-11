#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

#include <vector>
using namespace std;

template<class Monoid, class Operation>
struct segment_tree {
  int n;
  Monoid ide;
  vector<Monoid> node;
  Operation ope;
  segment_tree(int sz,Monoid ide, Operation ope) 
    : ide(ide), ope(ope){
      init(vector<Monoid>(sz, ide));
  }
  segment_tree(const vector<Monoid>& ini, Monoid ide, Operation ope) 
    : ide(ide), ope(ope) {
      init(ini);
  }
  void init(const vector<Monoid>& ini) {
    n = 1;
    while(n < ini.size()) n <<= 1;
    node.resize(n * 2 - 1);
    for(int i = 0;i < ini.size();i++)
      node[i + n - 1] = ini[i];
    for(int i = n - 2;i >= 0;i--) 
      node[i] = ope(node[i * 2 + 1], node[i * 2 + 2]);
  }
  void update(int i, Monoid x) {
    i += n - 1;
    node[i] = x;
    while(i > 0) {
      i = (i - 1) / 2;
      node[i] = ope(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }
  Monoid get(int i) {
    return node[i + n - 1];
  }
  Monoid get(int a,int b,int k = 0,int l = 0 ,int r = -1) {
    if(r < 0) r = n;
    if(a <= l && r <= b) return node[k];
    if(b <= l || r <= a) return ide;
    return ope(get(a,b,k * 2 + 1,l, (l + r) / 2),get(a,b,k * 2 + 2, (l + r) / 2 , r));
  }
};

i64 N;
vector<i64> a;

int main() {
  cin >> N;
  a.resize(N);
  rep(i,0,N - 1) cin >> a[i];
  i64 ok = 0;
  i64 ng = N;
  auto func = [](i64 a, i64 b) { return a + b; };

  vector<i64> b = a;
  sort(all(b));

  while(ng - ok > 1) {
    i64 mid = (ok + ng) / 2;
    segment_tree<i64, decltype(func)> seg(202020,0,func);
    seg.update(101010, 1);
    i64 now = 0;
    i64 ans = 0;
    for(int i = 0;i < N;i++) {
      if(a[i] < b[mid]) now--;
      else now++;
      ans += seg.get(0, 101010 + now + 1);
      seg.update(101010 + now, seg.get(101010 + now) + 1);
    }
    if(N * (N + 1) / 2 - ans < N * (N + 1) / 4 + 1) ok = mid;
    else ng = mid;
  }

  cout << b[ok] << endl;
}
