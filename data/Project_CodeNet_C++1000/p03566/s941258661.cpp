#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n;
vector<int> t, v;

//i is parameter(0-n+1)
int fni(int i, int tm) {
  int ret;
  if (i == 0)
    ret = tm;
  else if (i == n + 1)
    ret = t[n] - tm;
  else if (tm < t[i - 1])
    ret = -(tm - t[i - 1]) + v[i];
  else if (tm > t[i])
    ret = (tm - t[i]) + v[i];
  else
    ret = v[i];
  return ret;
}

int fn(int tm) {
  int ret = fni(0, tm);
  for (int i = 1; i <= n + 1; i++) {
    ret = min(ret, fni(i, tm));
  }
  return ret;
}

int main() {
  cin >> n;
  t.resize(n + 1, 0);
  v.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    t[i] *= 2;
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] *= 2;
  }


  for (int i = 0; i < n; i++) t[i + 1] += t[i];


  double ans = 0;
  for (int i = 0; i < t[n]; i ++) {
    ans += (fn(i) + fn(i + 1));

  }
    cout << fixed << setprecision(10) << ans / 8.0 << endl;

}