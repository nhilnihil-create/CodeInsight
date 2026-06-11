#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;
const ll INF = 1e18;

int main(int argc, char* argv[])
{
  ll N;
  ll T = 0;
  std::cin >> N;

  std::vector< ll > vt_s(N, 0);
  std::vector< ll > vt_e(N, 0);
  std::vector< double > vv(N, 0.0);

  for (ll i = 0; i < N; i++) {
    ll t;
    std::cin >> t;
    vt_s[i] = T;
    T += t;
    vt_e[i] = T;
  }
  for (ll i = 0; i < N; i++) {
    std::cin >> vv[i];
  }  

  double ans   = 0.0;
  double pre_v = 0.0;
  for (double t = 0.5; t <= T; t += 0.5) {
    double min_v = 100.0;
    min_v = std::min(min_v, t);
    min_v = std::min(min_v, T - t);

    for (ll i = 0; i < N; i++) {
      if (vt_s[i] <= t && t <= vt_e[i]) {
	min_v = std::min(min_v, vv[i]);
      }

      if (t < vt_s[i]) {
	min_v = std::min(min_v, vv[i] + (vt_s[i] - t));
      }
      
      if (vt_e[i] < t) {
	min_v = std::min(min_v, vv[i] + (t - vt_e[i]));
      }
    }

    ans += (pre_v + min_v) * 0.25;
    pre_v = min_v;
  }

  printf("%.15f\n", ans);
  
  return 0;
}
