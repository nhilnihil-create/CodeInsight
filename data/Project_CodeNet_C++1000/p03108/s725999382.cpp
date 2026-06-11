#include <bits/stdc++.h>
using namespace std;

class unionfind {
  vector<pair<int, int>> root;
  
public:
  unionfind(int n) {
    for (int i = 0; i < n; i++) {
      root.emplace_back(i, 1);
    }
  }
  
  int find(int n) {
    if (root.at(n).first == n) return n;
    return find(root.at(n).first);
  }
  
  void merge(int m, int n) {
    m = find(m); n = find(n);
    if (m == n) return;
    if (root.at(m).second < root.at(n).second) {
      root.at(m).first = n;
      root.at(n).second += root.at(m).second;
    } else {
      root.at(n).first = m;
      root.at(m).second += root.at(n).second;
    }
  }
  
  int get_size(int n) {
    return root.at(find(n)).second;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  unionfind t(n);
  vector<int64_t> ans(m + 1), a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a.at(i) >> b.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < m; i++) {
    if (t.find(a.at(i)) != t.find(b.at(i))) {
      ans.at(i + 1) = ans.at(i) + (int64_t) t.get_size(a.at(i)) * t.get_size(b.at(i));
      t.merge(a.at(i), b.at(i));
    } else {
      ans.at(i + 1) = ans.at(i);
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    cout << (int64_t) n * (n - 1) / 2 - ans.at(i) << endl;
  }
}
