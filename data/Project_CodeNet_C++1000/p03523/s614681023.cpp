#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

#define sqr(x) ((x) * (x))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef long long ll;

const int MOD = 1000000007;
const int INF = 1000000007;
const ll INFLL = 1000000000000000007LL;

void solve() {
  string S;
  cin >> S;
  string t = "AKIHABARA";
  set<string> vs;
  for (int i = 0; i < 1 << 9; i++) {
    string x;
    for (int j = 0; j < 9; j++) {
      if (t[j] == 'A' && (i >> j) & 1) {
      } else {
        x += t[j];
      }
    }
    vs.insert(x);
  }
  string ans = "NO";
  if (vs.count(S) > 0) ans = "YES";
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // cout << fixed << setprecision(12);

  solve();

  return 0;
}
