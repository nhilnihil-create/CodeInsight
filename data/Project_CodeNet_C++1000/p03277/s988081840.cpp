#include <bits/stdc++.h>
using namespace std;
class binary_indexed_tree {
  public:
    int n;
    vector<int> tree;
    binary_indexed_tree (int size) {
      n = size;
      tree.resize(n, 0);
    }
    int get (int x) {
      int ret = 0;
      for (; x >= 0; x &= x + 1, x--){
        ret += tree[x];
      }
      return ret;
    }
    void add (int x) {
      for (; x < n; x |= x + 1) {
        tree[x]++;
      }
    }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int lb = 0;
  int ub = 1e9 + 1;
  while (ub - lb > 1) {
    int md = (lb + ub) >> 1;
    long long inv = 0;
    binary_indexed_tree bit(2 * n + 1);
    int crr = n;
    bit.add(crr);
    for (int i = 0; i < n; i++) {
      if (a[i] >= md) {
        crr++;
      } else {
        crr--;
      }
      inv += bit.get(crr);
      bit.add(crr);
    }
    if (inv * 2 >= (long long) n * (n + 1) / 2) {
      lb = md;
    } else {
      ub = md;
    }
  }
  cout << lb << '\n';
  return 0;
}