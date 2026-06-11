#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> t(n + 2);
  int time = 0;
  for (int i = 1; i <= n; i++) {
    int in;
    cin >> in;
    t[i].first = time;
    time += in;
    t[i].second = time;
  }
  t[n + 1].first = time;
  t[n + 1].second = time;
  time *= 2;
  for (int i = 0; i <= n + 1; i++) {
    t[i].first *= 2;
    t[i].second *= 2;
  }
  vector<int> v(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<double> speed_limit(time + 1, 1 << 30);
  for (int j = 0; j <= n + 1; j++) {
    int start = t[j].first;
    int last = t[j].second;
    double cur = v[j];
    for (int i = start; i >= 0; i--) {
      speed_limit[i] = min(speed_limit[i], cur);
      cur += 0.5;
    }
    cur = v[j];
    for (int i = start; i <= last; i++) {
      speed_limit[i] = min(speed_limit[i], cur);
    }
    for (int i = last; i <= time; i++) {
      speed_limit[i] = min(speed_limit[i], cur);
      cur += 0.5;
    }
  }
  double ans = 0;
  for (int i = 0; i < time; i++) {
    ans += 1. * (speed_limit[i] + speed_limit[i + 1]) / 2 / 2;
  }
  cout << setprecision(20) << fixed << ans << '\n';
  return 0;
}