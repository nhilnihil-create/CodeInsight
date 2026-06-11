#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  int n, q;
  cin >> n >> q;
  string t;
  cin >> t;
  vector<int> a(n, 0), s(n + 1, 0);
  repi(i, 1, t.length()) {
    if (t[i - 1] == 'A' && t[i] == 'C') a[i] = 1;
  }
  rep(i, n) s[i + 1] = s[i] + a[i];
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l] << endl;
  }
  return 0;
}

