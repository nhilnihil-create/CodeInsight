#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int t[n];
  double max_v[n+1];
  for (int i=0; i<n; i++) cin>>t[i];
  for (int i=0; i<n; i++) cin>>max_v[i];
  max_v[n] = 0;

  double v[n+1];
  v[0] = 0;
  v[n] = 0;
  double cur_v = 0;
  for (int i=0; i<n-1; i++) {
    double max_vi = min(v[i] + t[i], max_v[i]);
    v[i+1] = max_vi;
    int acc_t = -t[i];
    for (int j=i+1; j<=n; j++) {
      acc_t += t[j-1];
      if (max_vi - acc_t <= max_v[j]) {
        continue;
      }
      v[i+1] = min(v[i+1], max_v[j] + acc_t);
    }
  }
  double ans = 0.0;
  for (int i=0; i<n; i++) {
    double v_start = v[i];
    double v_end = v[i+1];
    double v_high = (v_start + v_end + t[i]) / 2.0;
    v_high = min(v_high, max_v[i]);
    double t1 = v_high - v_start;
    double t2 = v_high - v_end;
    ans += (v_start + v_high) *t1 / 2.0 + (v_end + v_high) * t2 / 2.0 + v_high * (t[i] - t1 - t2);
  }
  printf("%.5lf", ans);
}