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
  vector<string> a, b, ab, o;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'B' && s.back() == 'A') ab.push_back(s);
    else if (s[0] == 'B') b.push_back(s);
    else if (s.back() == 'A') a.push_back(s);
    else o.push_back(s);
  }
  string t;
  if (a.size()) {
    t += a.back();
    a.pop_back();
  }
  for (auto &i : ab) t += i;
  if (b.size()) {
    t += b.back();
    b.pop_back();
  }
  int m = min(a.size(), b.size());
  for (int i = 0; i < m; i++) {
    t += a.back() + b.back();
    a.pop_back();
    b.pop_back();
  }
  for (auto &i : a) t += i;
  for (auto &i : b) t += i;
  for (auto &i : o) t += i;
  int ans = 0;
  for (int i = 0; i < (int)(t.size()) - 1; i++) {
    if (t.substr(i, 2) == "AB") ans++;
  }
  cout << ans << '\n';
}

signed main() {
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
