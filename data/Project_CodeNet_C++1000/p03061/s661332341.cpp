#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const int IDENTITY = 0;
int myGcd(int x, int y) {
  if(x == IDENTITY) {
    return y;
  }
  if(y == IDENTITY) {
    return x;
  }
  return gcd(x, y);
}

template <typename T> struct RMQ {
  const T IDENTITY = (T)0;
  int n;                                     // 葉の数
  vector<T> dat;                             // 完全二分木の配列
  RMQ(int n_) : n(), dat(n_ * 4, IDENTITY) { // 葉の数は 2^x の形
    int x = 1;
    while(n_ > x) {
      x *= 2;
    }
    n = x;
  }

  void update(int i, T x) {
    i += n - 1;
    dat[i] = x;
    while(i > 0) {
      i = (i - 1) / 2; // parent
      dat[i] = gcd(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  // the gcd element of [a,b)
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    if(r <= a || b <= l) {
      return IDENTITY;
    } else if(a <= l && r <= b) {
      return dat[k];
    } else {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return gcd(vl, vr);
    }
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  RMQ<int> tree(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    tree.update(i, a[i]);
  }
  int ans = 1;
  ans = max(tree.query(1, n), tree.query(0, n - 1));
  for(int i = 1; i < n - 1; i++) {
    ans = max(ans, gcd(tree.query(0, i), tree.query(i + 1, n)));
  }
  cout << ans << endl;
  return 0;
}