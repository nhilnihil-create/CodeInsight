#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T> class BinaryIndexedTree { // 1-indexed
  int N;
  std::vector<T> bit;

public:
  BinaryIndexedTree(int n) : N(n), bit(n + 1, 0) {}

  void add(int index, T num) {
    for (int x = index; x <= N; x += x & -x)
      bit[x] += num;
  }

  T sum(int index) {
    int ret = 0;
    for (int x = index; x > 0; x -= x & -x)
      ret += bit[x];
    return ret;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto aa = a;
  sort(aa.begin(), aa.end());
  int right = n, left = -1;
  while (right - left > 1) {
    int mid = (right + left) / 2;
    int med = aa[mid];
    auto b = a;
    for (auto &x : b) {
      if (x < med)
        x = -1;
      else
        x = 1;
    }
    for (int i = 1; i < n; ++i) {
      b[i] += b[i - 1];
    }
    BinaryIndexedTree<int> BIT(300001);
    ll num = 0;
    BIT.add(100001, 1);
    for (auto x : b) {
      num += BIT.sum(x + 100001);
      BIT.add(x + 100001, 1);
    }
    // cout << med << " " << num << endl;
    ll m = ((ll(1 + n) * n) / 2);
    if (num >= m / 2 + m % 2) {
      left = mid;
    } else {
      right = mid;
    }
  }
  cout << aa[left] << endl;
}