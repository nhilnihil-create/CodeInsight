#include <bits/stdc++.h>
using namespace std;
class binary_indexed_tree {
  public:
    int n;
    vector<int> tree;
    binary_indexed_tree (int size) {
      n = size;
      tree.resize(n + 1, 0);
    }
    int sum (int i) {
      int ret = 0;
      while (i) {
        ret += tree[i];
        i -= i & -i;
      }
      return ret;
    }
    void add (int i, int x) {
      while (i <= n) {
        tree[i] += x;
        i += i & -i;
      }
    }
};
int n;
vector<int> a;
bool medianOrLess (int x) {
  vector<int> acm(n + 1, n + 1);
  for (int i = 0; i < n; i++) {
    acm[i + 1] = acm[i];
    if (a[i] >= x) {
      acm[i + 1]++;
    } else {
      acm[i + 1]--;
    }
  }
  long long inv = 0;
  binary_indexed_tree bit(2 * n + 1);
  for (int i = 0; i <= n; i++) {
    inv += bit.sum(acm[i]);
    bit.add(acm[i], 1);
  }
  if (inv >= (long long) n * (n + 1) / 2 - (long long) n * (n + 1) / 4) {
    return true;
  } else {
    return false;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int lb = 0;
  int ub = 1e9 + 1;
  while (ub - lb > 1) {
    int md = (lb + ub) / 2;
    if (medianOrLess(md)) {
      lb = md;
    } else {
      ub = md;
    }
  }
  cout << lb << '\n';
  return 0;
}