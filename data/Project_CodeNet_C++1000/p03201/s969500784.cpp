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

  int n;
  cin >> n;
  vl a(n);
  map<ll, int> mp;
  REP(i, n) {
    cin >> a[i];
    mp[a[i]]++;
  }

  sort(a.rbegin(), a.rend());
  int ans = 0;
  REP(i, n) {
    if (mp[a[i]] == 0)
      continue;
    mp[a[i]]--;
    ll t = 1;
    while (t <= a[i]) {
      t <<= 1;
    }
    if (mp[t - a[i]]) {
      ans++;
      mp[t - a[i]]--;
    }
  }
  cout << ans << endl;
  return 0;
}
