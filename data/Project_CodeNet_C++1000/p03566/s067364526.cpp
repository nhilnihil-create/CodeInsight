#include <iostream>
#include <vector>
#include <iomanip>
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main()
{
  int N; cin >> N;

  vector<int> t(N), v(N);
  int T = 0;
  REP(i, N) { cin >> t[i]; T += t[i]; }
  REP(i, N) cin >> v[i];

  vector<double> maxv(2*T + 1, 1e10);
  maxv[0] = maxv[2*T] = 0;
  int now = 0;
  REP(i, N) {
    for (int j = now; j <= now + 2*t[i]; j++) {
      maxv[j] = min(maxv[j], (double)v[i]);
    }
    now += 2*t[i];
  }

  for (int i = 1; i <= 2*T; i++) {
    maxv[i] = min(maxv[i], maxv[i-1] + 0.5);
  }
  for (int i = 2*T-1; i >= 0; i--) {
    maxv[i] = min(maxv[i], maxv[i+1] + 0.5);
  }

  //for (int i = 0; i <= 2*T; i++) {
  //  cout << (i / 2.0) << ',' << maxv[i] << endl;
  //}

  double ans = 0;
  REP(i, 2*T) {
    ans += (maxv[i] + maxv[i + 1])*0.25;
  }
  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}