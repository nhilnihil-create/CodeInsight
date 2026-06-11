#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"


#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << endl; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, C;
  cin >> n >> C;
  vector<vi> imos(C, vi((int)1e5 + 1, 0));
  REP(i, n) {
    int s, t, c;
    cin >> s >> t >> c;
    s--;
    t--;
    c--;
    imos[c][s]++;
    imos[c][t + 1]--;
  }

  int ans = 0;
  FOR(i, 1, (int)1e5 + 1) {
    int cur = 0;
    REP(j, C) {
      imos[j][i] += imos[j][i - 1];
      if (imos[j][i] > 0)
        cur++;
    }
    chmax(ans, cur);
  }
  cout << ans << endl;

  return 0;
}
