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

template <class T> void say(bool val, T yes = "Yes", T no = "No") { cout << (val ? yes : no) << "\n"; }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}


#line 2 "tmp.cpp"

void solve(const int n, const string &s, const int k) {
  ll d = 0, m = 0, dm = 0, ans = 0;
  vl rd(n, 0), rm(n, 0);
  REP(i, n) {
    if (rd[i] < 0) {
      d -= 1;
      dm -= m;
    }
    if (rm[i] < 0) {
      m -= 1;
    }

    if (s[i] == 'D') {
      d++;
      if (i + k < n)
        rd[i + k]--;
    }
    if (s[i] == 'M') {
      m++;
      dm += d;
      if (i + k < n)
        rm[i + k]--;
    }
    if (s[i] == 'C') {
      ans += dm;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  REP(i, q) {
    int k;
    cin >> k;
    solve(n, s, k);
  }
  return 0;
}
