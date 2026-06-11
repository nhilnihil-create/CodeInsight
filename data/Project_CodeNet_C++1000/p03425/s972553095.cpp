#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, ss, ee) for (int i = (ss); i < (ee); ++i)

int x[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
int y[] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
int z[] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

void solve() {
  int N;
  cin >> N;
  string s;
  map<char, ll> m;
  rep(i, 0, N) {
    cin >> s;
    m[s[0]]++;
  }

  vector<ll> v(5);
  v[0] = m['M'];
  v[1] = m['A'];
  v[2] = m['R'];
  v[3] = m['C'];
  v[4] = m['H'];

  ll ans = 0;
  rep(i, 0, 10) { ans += v[x[i]] * v[y[i]] * v[z[i]]; }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}