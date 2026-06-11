#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll MOD = 1000000007;
ll INFL = 1ll << 60;
ll INF = 1 << 28;

template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
  cout << "{";
  for (int i = 0; i < vec.size(); i++)
    os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  cout << "}";
  return os;
}

// ====================================================================

int main() {
  string s;
  cin >> s;
  int gx, gy;
  cin >> gx >> gy;

  vector<int> idox, idoy;
  set<int> cangox, cangoy;
  int mode = 0, count = 0;
  bool tokubetu = true;
  for (int i = 0; i <= s.size(); i++) {
    if (s[i] == 'T' || i == s.size()) {
      if (tokubetu) {
        cangox.insert(count);
        tokubetu = false;
      } else if (mode == 0)
        idox.push_back(count);
      else
        idoy.push_back(count);
      mode ^= 1;
      count = 0;
    }
    if (s[i] == 'F') count++;
  }

  if (cangox.size() == 0) cangox.insert(0);
  cangoy.insert(0);

  // ヨコ移動について
  for (int i = 0; i < idox.size(); i++) {
    set<int> res(cangox);
    cangox.clear();
    for (auto x : res) {
      cangox.insert(x + idox[i]);
      cangox.insert(x - idox[i]);
    }
  }

  // タテ移動について
  for (int i = 0; i < idoy.size(); i++) {
    set<int> next(cangoy);
    cangoy.clear();
    for (auto y : next) {
      cangoy.insert(y + idoy[i]);
      cangoy.insert(y - idoy[i]);
    }
  }

  if (cangox.count(gx) && cangoy.count(gy))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
