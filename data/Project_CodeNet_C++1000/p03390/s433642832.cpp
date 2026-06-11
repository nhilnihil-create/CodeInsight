#include <iostream>
using namespace std;

inline int64_t F(int64_t x, int64_t k, int64_t l) {
  return -x * x + (k + 1 + l) * x;
}

// max { F(x,k,l) } を計算する。ただしxは1以上k以下の整数。
int64_t FindMaximumValue(int64_t k, int64_t l) {
  int64_t lb = 1, ub = k;
  while (ub - lb > 1) {
    int64_t mid = (ub + lb) / 2;

    if (F(mid, k, l) >= F(mid + 1, k, l)) ub = mid;
    else lb = mid;
  }
  return F(ub, k, l);
}

int64_t BinarySearch(int64_t me, int64_t other) {
  int64_t lb = 0, ub = me;
  while (ub - lb > 1) {
    int64_t mid = (ub + lb) / 2;

    if (FindMaximumValue(mid, other) < me * other) lb = mid;
    else ub = mid;
  }
  return lb;
}

int main() {
  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int64_t a, b;
    cin >> a >> b;

    int64_t a_bound = BinarySearch(a, b),
            b_bound = BinarySearch(b, a);
    
    // cerr << "a_bound " << a_bound << " b_bound " << b_bound << endl;
    
    cout << a_bound + b_bound + min(a - 1 - a_bound, b - 1 - b_bound) << endl;
  }

  return 0;
}