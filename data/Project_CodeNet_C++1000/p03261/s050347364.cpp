#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> w(n);
  rep(i, n) cin >> w.at(i);
  char end;
  map<string, int> mp;
  bool ok = true;
  rep(i, n) {
    bool startIsOk = true;
    if (i != 0) {
      startIsOk = (end == w.at(i)[0]);
    }
    ok = mp.count(w.at(i)) == 0 && startIsOk;
    if (!ok) {
      break;
    }
    mp[w.at(i)]++;
    end = w.at(i).back();
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
