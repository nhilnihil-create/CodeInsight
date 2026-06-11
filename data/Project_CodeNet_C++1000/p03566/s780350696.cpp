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
  vector<int> t(n + 2, 0);
  vector<double> v(n + 2, 0);
  int sum = 0;
  REP(i, n) {
    cin >> t[i + 1];
    sum += t[i + 1];
    t[i + 1] += t[i];
  }
  t[n + 1] = sum;
  REP(i, n) { cin >> v[i + 1]; }

  vector<double> ans(2 * sum + 1, 0.0);
  FOR(j, 1, 2 * sum + 1) {
    double tmp = 2 * sum;
    double time = (double)j / 2;

    FOR(i, 1, n + 1) {
      if (time < t[i - 1]) {
        chmin(tmp, t[i - 1] - time + v[i]);
        // cout << "top: " MM t[i - 1] - time + v[i] << endl;

      } else if (t[i] < time) {
        chmin(tmp, time - t[i] + v[i]);
        // cout << "middle: " MM time - t[i] + v[i] << endl;
      } else {
        chmin(tmp, v[i]);
        // cout << "bottom: " MM v[i] << endl;
      }
    }
    chmin(tmp, time);
    chmin(tmp, sum - time);
    ans[j] = tmp;
    // cout << time MM ans[j] << endl;
  }

  double val = 0;
  FOR(i, 1, 2 * sum + 1) { val += (ans[i] + ans[i - 1]) / 4; }
  coutd(5) << val << endl;

  return 0;
}
