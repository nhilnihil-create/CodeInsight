#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<functional>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// bit
template<typename T, int NN>
struct bit {
  typedef std::function<T(T,T)> OP;
  T data_[NN], e_; // 0-base
  OP& op_;
  bit(OP& op, T e) : e_(e), op_(op) { std::fill_n(data_, NN, e_); }
  int lb(int i){ return i&-i; }
  T query(int i) { // 1-base
    T res = e_;
    while(i > 0) { res = op_(res, data_[i-1]); i -= lb(i); }
    return res;
  }
  void add(int i, T const& v) { // 1-base
    while(i <= NN) { data_[i-1] = op_(data_[i-1], v); i += lb(i); }
  }
};

using bit2k = bit<int, 2048>;
bit2k::OP min_op = [](int x, int y){ return std::min(x, y); };
bit2k::OP max_op = [](int x, int y){ return std::max(x, y); };

int const INF = 1e9+5;

int main() {
  int N; std::cin >> N;
  std::vector<int> a(N+2);
  for(int i = 0; i < N+2; ++i) std::cin >> a[i];
  
  std::vector<bit2k> xy(N+1, bit2k(min_op,  INF));
  std::vector<bit2k> yx(N+1, bit2k(max_op, -INF));
  for(int y = N; y >= 1; --y) {
    for(int x = N; x > y; --x) { // play for Y
      int res = std::abs(a[N+1] - a[x]);
      res = std::min(res, xy[x].query(N-x));
      yx[y].add(N+1-x, res);
    }
    for(int x = y-1; x >= 0; --x) { // play for X
      int res = std::abs(a[N+1] - a[y]);
      res = std::max(res, yx[y].query(N-y));
      if(y==1 && x==0) fin(res);
      xy[x].add(N+1-y, res);
    }
  }
  return 0;
}
