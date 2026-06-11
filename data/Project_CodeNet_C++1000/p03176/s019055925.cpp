#include <bits/stdc++.h>
using namespace std;

class segtree {
  int n;
  vector<int64_t> v;
  
public:
  segtree(int k) {
    n = k;
    v = vector<int64_t>(2 * k);
  }
  
  void update(int x, int64_t k) {
    int index = x + n - 1;
    while (index) {
      v.at(index) = max(v.at(index), k);
      index /= 2;
    }
  }
  
  int64_t query(int k) {
    int64_t l = n, res = 0;
    k += n;
    while (l < k) {
      if (k % 2) {
        res = max(res, v.at(k - 1));
      }
      k /= 2;
      if (l % 2) {
        res = max(res, v.at(l));
        l++;
      }
      l /= 2;
    }
    return res;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int64_t> h(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  
  segtree t(n);
  for (int i = 0; i < n; i++) {
    t.update(h.at(i), t.query(h.at(i)) + a.at(i));
  }
  
  cout << t.query(n) << endl;
}
