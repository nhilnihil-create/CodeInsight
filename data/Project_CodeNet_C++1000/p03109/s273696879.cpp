// J'aime
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
  string in; cin >> in;
  stringstream ss(in);
  for (int i = 0; i < 2; i++) {
    string s;
    getline(ss, s, '/');
    int t = stoi(s);
    if (i == 0 && t < 2019) {
      cout << "Heisei" << '\n';
      return;
    }
    if (i == 0 && t > 2019) {
      cout << "TBD" << '\n';
      return;
    }
    if (i == 1 && t <= 4) {
      cout << "Heisei" << '\n';
      return;
    }
    if (i == 1 && t > 4) {
      cout << "TBD" << '\n';
      return;
    }
  }
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
