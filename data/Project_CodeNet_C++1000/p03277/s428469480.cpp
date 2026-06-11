// D - Median of Medians

// 長さNの数列aのすべての部分列に対して, 中央値を求める
// それらすべての中央値を集めた数列に対する中央値を出力する

// 1 <= N <= 1e5
// 1 <= ai <= 1e9

// 解説: 二分探索・累積和・転倒数
//   [l,r]の中央値がX以上である ⇔ [l,r]はX以上の値が過半数を占める
//   X以上の要素を+1, X未満の要素を-1に置き換えて, 累積和Sを求めると,
//   区間和が正の数になるような[l,r]を数え上げる問題に言い換えられる
//   さらに, S[0,l] <= S[0,r]であるような[l,r]を数え上げる問題に言い換えられる

// 解法: O(N^2)
//   lを全探索
//   rを増やしながら, (abs(al未満の個数 - al超の個数) <= alと等しい個数)であるような[l,r]をカウント
//   これにより, 各aiが中央値になる回数が分かる

#include<vector>
#include<unordered_map>
#include<algorithm>
template<typename T> class Compression {
 public:
  Compression(const std::vector<T>& list) : value_(list) {
    std::sort(begin(value_), end(value_));
    value_.erase(std::unique(begin(value_), end(value_)), end(value_));
    for(int i = 0; i < value_.size(); ++i) index_[value_[i]] = i;
  }
  int size() const {return value_.size();}
  int index(const T& v) const {return index_.at(v);}
  int operator[](const int i) const {return value_.at(i);}
 private:
  std::unordered_map<T, int> index_;
  std::vector<T> value_;
};

#include<vector>
using Size = int;
template<typename T> class SegmentTree {
 public:
  SegmentTree(Size N) : N(size(N)), node_(2 * size(N) - 1) {}
  void update(Size i, T v) {
    i += N - 1;
    node_[i] = v;
    while(i != parent(i)) {
      i = parent(i);
      node_[i] = node_[lchild(i)] + node_[rchild(i)];
    }
  }
  T find(Size a, Size b) const {return find(a, b, 0, 0, N);}
 private:
  constexpr Size pop_lsb(Size N) const {return N & (N - 1);}
  constexpr Size msb(Size N) const {while(pop_lsb(N)) N = pop_lsb(N); return N;}
  constexpr Size size(Size N) const {return pop_lsb(N) ? msb(N) << 1 : N;}
  inline Size parent(Size n) const {return (n - 1) / 2;}
  inline Size lchild(Size n) const {return 2 * n + 1;}
  inline Size rchild(Size n) const {return 2 * n + 2;}
  T find(Size a, Size b, Size k, Size l, Size r) const {
    if(b <= l || r <= a) return 0;
    if(a <= l && r <= b) return node_[k];
    auto m = (l + r) / 2;
    return find(a, b, lchild(k), l, m) + find(a, b, rchild(k), m, r);
  }
  const Size N;
  std::vector<T> node_;
};

#include<bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  vector<long long> A(N);
  for(auto& i: A) cin >> i;

  auto M = N + (N * (N-1) / 2);

  auto ok = [&](auto X) {
    vector<long long> S = {0};
    for(auto i: A) S.emplace_back(S.back() + (i<X ? -1 : 1));
    Compression<long long> C(S);
    SegmentTree<long long> T(C.size() + 1);
    long long cnt = 0;
    for(auto i=0; i<S.size(); ++i) {
      cnt += T.find(0, C.index(S[i]) + 1);
      auto x = T.find(C.index(S[i]), C.index(S[i]) + 1);
      T.update(C.index(S[i]), x + 1);
    }
    return (M+1)/2 <= cnt;
  };

  long long l = 1, h = 1e9+1;
  while(1 < h-l) {
    auto m = (l + h) / 2;
    if(ok(m)) l = m;
    else      h = m;
  }
  cout << l << endl;
}
