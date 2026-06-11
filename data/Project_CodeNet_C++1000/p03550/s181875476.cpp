#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<functional>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

template<typename T, int MAXNN>
struct seg_tree {
  typedef std::function<T(T,T)> OP;
  T data_[MAXNN*2-1], e_;
  int NN;
  OP& op_;

  seg_tree(int N, OP& op, T e) : e_(e), op_(op) {
    NN = 1;
    while(NN < N) NN *= 2;
    std::fill_n(data_, NN*2-1, e);
  }
  void update(int k, T v) {
    k += NN-1;
    data_[k] = v;
    while(k > 0) {
      k = (k-1)/2;
      data_[k] = op_(data_[k*2+1], data_[k*2+2]);
    }
  }
  int query(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) return e_;
    if(a <= l && r <= b) return data_[k];
    int m = (l+r)/2;
    int vl = query(a, b, k*2+1, l, m);
    int vr = query(a, b, k*2+2, m, r);
    return op_(vl, vr);
  }
  int query(int a, int b){ return query(a, b, 0, 0, NN); }
};


using seg2k = seg_tree<int, 2048>;
seg2k::OP min_op = [](int x, int y){ return std::min(x, y); };
seg2k::OP max_op = [](int x, int y){ return std::max(x, y); };

int const INF = 1e9+5;

int main() {
  int N; std::cin >> N;
  std::vector<int> a(N+2);
  for(int i = 0; i < N+2; ++i) std::cin >> a[i];
  
  std::vector<seg2k> yx_max(N+1, seg2k(N+1, max_op, -INF));
  std::vector<seg2k> xy_min(N+1, seg2k(N+1, min_op,  INF));
  for(int y = N; y >= 1; --y) {
    for(int x = N; x > y; --x) { // play for Y
      int res = std::abs(a[N+1] - a[x]);
      res = std::min(res, xy_min[x].query(x+1, N+1));
      yx_max[y].update(x, res);
    }
    for(int x = y-1; x >= 0; --x) { // play for X
      int res = std::abs(a[N+1] - a[y]);
      res = std::max(res, yx_max[y].query(y+1, N+1));
      if(y==1 && x==0) fin(res);
      xy_min[x].update(y, res);
    }
  }
  return 0;
}
