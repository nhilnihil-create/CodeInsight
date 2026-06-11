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

template <class T> T gcd(T n, T m) { return n ? gcd(m % n, n) : m; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  REP(num, t) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) {
      cout << "No" << endl;
    } else if (d < b) {
      cout << "No" << endl;
    } else if (c >= b) {
      cout << "Yes" << endl;
    } else {
      if (a % b > c) {
        cout << "No" << endl;
      } else if (d % b == 0LL) {
        cout << "Yes" << endl;
      } else {
        ll g = gcd(b, d);
        if (b - g + (a % g) <= c) {
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
  }
  return 0;
}
