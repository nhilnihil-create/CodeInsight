#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<p> lr;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    lr.emplace_back(l, r);
  }
  vector<int> ruiseki(n + 1, 0);
  for (int i = 1; i < n; i++) {
    ruiseki[i] = ruiseki[i - 1];
    if (s[i - 1] == 'A' && s[i] == 'C') {
      ruiseki[i]++;
    }
    // cout << ruiseki[i] << endl;
  }
  rep(i, q) {
    int ans = ruiseki[lr[i].second - 1] - ruiseki[lr[i].first - 1];
    cout << ans << endl;
  }
  return 0;
}