#include <bits/stdc++.h>
using namespace std;

int n, sumt = 0;
vector<int> t, v;
vector<double> lim;

double solve();

int main() {
  cout << fixed << setprecision(10);
  cin >> n;
  t.assign(n + 2, 0);
  for(int i = 1; i <= n; ++i) cin >> t[i];
  v.assign(n + 2, 0);
  for(int i = 1; i <= n; ++i) cin >> v[i];
  n += 2;
  cout << solve() << endl;
  return 0;
}

double solve() {
  for(int i = 0; i < n; ++i) sumt += t[i] * 2;
  lim.assign(sumt + 1, 1000000);
  int nowt = 0;
  for(int i = 0; i < n; ++i) {
    double nowv = v[i];
    for(int j = 0; j <= nowt; ++j) {
      lim[nowt - j] = min(lim[nowt - j], nowv);
      nowv += 0.5;
    }
    for(int j = nowt; j <= nowt + t[i] * 2; ++j)
      lim[j] = min(lim[j], (double)v[i]);
    nowt += t[i] * 2;
    nowv = v[i];
    for(int j = nowt; j < lim.size(); ++j) {
      lim[j] = min(lim[j], nowv);
      nowv += 0.5;
    }
  }
  double ans = 0;
  for(int i = 1; i < lim.size(); ++i)
    ans += (lim[i] + lim[i - 1]) * 0.25;

  return ans;
}