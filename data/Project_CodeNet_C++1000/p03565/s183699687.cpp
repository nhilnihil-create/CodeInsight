// I love
// Chemise Blanche

#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << __LINE__ << " > " << #x << " = " << (x) << endl

void MAIN() {
  string s, t;
  cin >> s >> t;
  vector<string> res;
  for (int i = 0; i < s.size() - t.size() + 1; i++) {
    string l = s;
    int b = 1;
    for (int j = 0; j < t.size(); j++) {
      if (l[i + j] == '?') l[i + j] = t[j];
      if (l[i + j] != t[j]) {
        b = 0;
        break;
      }
    }
    if (b) {
      for (auto &j : l) {
        if (j == '?') j = 'a';
      }
      res.push_back(l);
    }
  }
  if (res.empty()) {
    cout << "UNRESTORABLE" << '\n';
    return;
  }
  sort(all(res));
  cout << res.front() << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
