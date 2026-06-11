#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

string s;
int n, ans = 0;

void check() {
  set<char> d;
  for (auto &i : s) d.insert(i);
  if (d.size() < 3) return;
  int k = stoi(s);
  if (k <= n) ans++;
}

void brute(int i) {
  for (auto &j : {'3', '5', '7'}) {
    s += j;
    check();
    if (i < 9) brute(i + 1);
    s.pop_back();
  }
}

void MAIN() {
  cin >> n;
  brute(1);
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
