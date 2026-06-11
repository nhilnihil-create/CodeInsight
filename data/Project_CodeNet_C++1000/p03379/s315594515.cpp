#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n; cin >> n;
  vector<ii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].fi;
    a[i].sc = i;
  }
  sort(all(a));
  vector<int> res(n);
  for (int i = 0; i < n; i++) {
    if (i < n / 2) res[a[i].sc] = a[n / 2].fi;
    else res[a[i].sc] = a[n / 2 - 1].fi;
  }
  for (auto &i : res) cout << i << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
