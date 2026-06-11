#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()

/* include file*/
#include <functional>
#include <vector>
using namespace std;

template <class Monoid>
struct Segment {
  using Func = function<Monoid(Monoid, Monoid)>;

  vector<Monoid> node;
  Monoid ide;
  int n = 1;

  Func bin_f;
  Func update_f;

  Segment(const vector<Monoid>& init, Monoid ide_, Func f_, Func u_f)
      : bin_f(f_), ide(ide_), update_f(u_f) {
    int sz = init.size();
    while (n < sz) n *= 2;
    node.assign(n * 2 - 1, ide);
    for (int i = 0; i < sz; i++) node[i + n - 1] = init[i];
    for (int i = n - 2; i >= 0; i--)
      node[i] = bin_f(node[i * 2 + 1], node[i * 2 + 2]);
  }

  void update(int i, Monoid x) {
    i += n - 1;
    node[i] = update_f(node[i], x);
    while (i) {
      i = (i - 1) / 2;
      node[i] = bin_f(node[i * 2 + 1], node[i * 2 + 2]);
    }
  }

  Monoid get_inter(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (a <= l && r <= b) return node[k];
    if (r <= a || b <= l) return ide;

    Monoid lm = get_inter(a, b, k * 2 + 1, l, (l + r) / 2);
    Monoid rm = get_inter(a, b, k * 2 + 2, (l + r) / 2, r);
    return bin_f(lm, rm);
  }
};

// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2730414#1
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2730425#1
int main(){
  i64 N;
  cin >> N;
  vector<i64> A(N);
  rep(i,0,N - 1) cin >> A[i];
  i64 ng = 0;
  i64 ok = 1e9 + 1;

  while(abs(ok - ng) > 1){
    i64 mid = (ok + ng) / 2;
    i64 sum = 0;
    Segment<i64> seg(vector<i64>(202020,0),0,[](i64 a,i64 b){return a + b;},[](i64 a,i64 b){return a + b;});
    seg.update(101010,1);
    i64 cnt = 0;
    rep(i,0,N - 1){
      if(A[i] <= mid) sum++;
      else sum--;
      cnt += seg.get_inter(0,101010 + sum - 1 + 1);
      seg.update(101010 + sum , 1);
    }
    if(cnt >= N * (N + 1) / 4 + 1) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

}
