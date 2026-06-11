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
  string s;
  cin >> s;
  int o = (1 <= stoi(s.substr(0, 2))) && (stoi(s.substr(0, 2)) <= 12);
  int t = (1 <= stoi(s.substr(2, 2))) && (stoi(s.substr(2, 2)) <= 12);
  if (o && t) cout << "AMBIGUOUS" << '\n';
  else if (o) cout << "MMYY" << '\n';
  else if (t) cout << "YYMM" << '\n';
  else cout << "NA" << '\n';
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
