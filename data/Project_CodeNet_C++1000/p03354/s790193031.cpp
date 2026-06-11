#include <bits/stdc++.h>
using namespace std;

class unionfind {
  vector<int> par;
  
public:
  unionfind(int n) {
    for (int i = 0; i < n; i++) {
      par.push_back(i);
    }
  }
  
  int find(int n) {
    if (n == par.at(n)) return n;
    return par.at(n) = find(par.at(n));
  }
  
  void merge(int m, int n) {
    m = find(m); n = find(n);
    par.at(m) = n;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), x(m), y(m);
  for (int i = 0; i < n; i++) {
    cin >> p.at(i);
    p.at(i)--;
  }
  for (int i = 0; i < m; i++) {
    cin >> x.at(i) >> y.at(i);
    x.at(i)--;
    y.at(i)--;
  }
  unionfind t(n);
  for (int i = 0; i < m; i++) {
    t.merge(x.at(i), y.at(i));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (t.find(i) == t.find(p.at(i))) {
      ans++;
    }
  }
  cout << ans << endl;
}
